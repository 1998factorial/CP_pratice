#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
const ll INF = 1e18;
const int lim = 1e5+10;
#define ID 0
 
struct min_lazy_tree{
 
    struct node{
        ll val , lazy;
        node(){}
        node(ll v , ll z) : val(v) , lazy(z) {}
    };
 
    node tree[maxn << 2];
 
    void push_down(int l , int r , int id){
        if(l > r)return;
        if(tree[id].lazy != 0 && l < r){
            tree[id << 1].lazy += tree[id].lazy;
			tree[id << 1 | 1].lazy += tree[id].lazy;
			tree[id << 1].val += tree[id].lazy;
			tree[id << 1 | 1].val += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }
 
    node merge(node l , node r){
        node ret(0 , 0);
        if(l.val > r.val){
            ret.val = l.val;
        }
        else{
            ret.val = r.val;
        }
        return ret;
    }
 
    void build(int l , int r , int id){
        if(l > r)return;
        if(l == r){
            //tree[id].val = F2[l];
            tree[id].val=tree[id].lazy=0;
            if(ID)printf("tree[%d %d] = %lld\n" , l , r , tree[id].val);
        }
        else{
            int mid = (l + r) >> 1;
            build(l , mid , id << 1);
            build(mid + 1 , r , id << 1 | 1);
            tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
            if(ID)printf("tree[%d %d] = %lld\n" , l , r , tree[id].val);
        }
    }
 
    void update(int l , int r , int x , int y , int id , ll v){ // support range update
        if(l > r || x > y || r < x || l > y)return;
        push_down(x , y , id);
        if(l <= x && y <= r){
            tree[id].val += v;
            tree[id].lazy += v;
            return;
        }
        int mid = (x + y) >> 1;
        if(r <= mid){
            update(l , r , x , mid , id << 1 , v);
        }
        else if(l > mid){
            update(l , r , mid + 1 , y , id << 1 | 1 , v);
        }
        else{
            update(l , r , x , mid , id << 1 , v);
            update(l , r , mid + 1 , y , id << 1 | 1 , v);
        }
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }
 
    ll query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return -INF;
        push_down(x , y , id);
        if(l <= x && y <= r){
            return tree[id].val;
        }
        int mid = (x + y) >> 1;
        if(r <= mid){
            return query(l , r , x , mid , id << 1);
        }
        if(l > mid){
            return query(l , r , mid + 1 , y , id << 1 | 1);
        }
        return max(
            query(l , r , x , mid , id << 1) ,
            query(l , r , mid + 1 , y , id << 1 | 1)
        );
    }
 
    int query(int l , int r , int id){
        if(tree[id].val <= 0)return -1;
        if(l == r)return l;
        push_down(l , r , id);
        int mid = (l + r) >> 1;
        if(tree[id << 1 | 1].val > 0)return query(mid + 1 , r , id << 1 | 1);
        return query(l , mid , id << 1);
    }
 
} T;
int main(){
    int t;
    scanf("%d" , &t);
    while(t--){
        int N , M , max_v = 0;
        scanf("%d %d" , &N , &M);
        vector<int> a(N + 1);
        for(int i = 1; i <= N; ++i){
            scanf("%d" , &a[i]);
            max_v = max(a[i] , max_v);
        }
        vector<vector<int>> groups;
        for(int i = 1; i <= M; ++i){
            int sz;
            scanf("%d" , &sz);
            vector<int> group(sz);
            for(int j = 0; j < sz; ++j){
                scanf("%d" , &group[j]);
            }
            groups.push_back(group);
        }
        T.build(1 , lim , 1);
        for(int i = 1; i <= N; ++i){
            T.update(1 , a[i] , 1 , lim , 1 , 1);
            printf("[%d %d]+=1\n",1,a[i]);
        }
        vector<double> sum(M , 0);
        multiset<int> bases;
        for(int i = 0; i < M; ++i){
            for(int j: groups[i])sum[i] += j;
            int base = ceil(sum[i] / (int)groups[i].size());
            if((sum[i] / (int)groups[i].size()) * (int)groups[i].size() == sum[i])++base;
            T.update(base , lim , 1 , lim , 1 , -1);
            printf("[%d %d]-=1\n",base,lim);
            bases.insert(base);
        }
        for(int i = 0; i < M; ++i){
            int base = ceil(sum[i] / (int)groups[i].size());
            if((sum[i] / (int)groups[i].size()) * (int)groups[i].size() == sum[i])++base;
            T.update(base , lim , 1 , lim , 1 , 1);
            //printf("[%d %d]+=1\n",base,lim);
            bases.erase(bases.find(base));
            for(int j : groups[i]){
                sum[i] -= j;
                //DEBUG(sum[i]);
                base = ceil(sum[i] / (int)(groups[i].size() - 1));
                if((sum[i] / (int)groups[i].size()-1) * (int)(groups[i].size()-1) == sum[i])++base;
                bases.insert(base);
                T.update(base , lim , 1 , lim , 1 , -1);
                //printf("[%d %d]-=1\n",base,lim);
                //cout<<"bases="<<*bases.rbegin()<<endl;
                if(T.query(*bases.rbegin() , lim , 1 , lim , 1) < 0){
                    cout << 0;
                }
                else cout << 1;
                T.update(base , lim , 1 , lim , 1 , 1);
                //printf("[%d %d]+=1\n",base,lim);
                bases.erase(bases.find(base));
                sum[i] += j;
            }
            base = ceil(sum[i] / (int)groups[i].size());
            if((sum[i] / (int)groups[i].size()) * (int)groups[i].size() == sum[i])++base;
            T.update(base , lim , 1 , lim , 1 , -1);
            //printf("[%d %d]-=1\n",base,lim);
            bases.insert(base);
        }
        cout<<endl;
    }
}