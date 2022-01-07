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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
// exist optimal solution such that (s[i] + a[i]) <= (s[i + 1] + a[i + 1])
// suppose in optimal solution exist i such that s[i] + a[i] > s[i + 1] + a[i + 1]
// we have a[i] <= s[i + 1] implies s[i] > a[i + 1]
// swap i and i+1 will not make the answer worse 
namespace max_lazy_tree {
    typedef long long ll;
    const int maxn = 1e6 + 10;
    const ll inf64 = 1e18;
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
            tree[id].val = tree[id].lazy = 0;
        }
        else{
            int mid = (l + r) >> 1;
            build(l , mid , id << 1);
            build(mid + 1 , r , id << 1 | 1);
            tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
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
 
    void update_point(int pos , int x , int y , int id , ll v){ // support range update
        if(pos < x || pos > y || x > y)return ;
        push_down(x , y , id);
        if(y == x && x == pos){
            tree[id].val = v;
            return;
        }
        int mid = (x + y) >> 1;
        if(pos <= mid){
            update_point(pos , x , mid , id << 1 , v);
        }
        else{
            update_point(pos , mid + 1 , y , id << 1 | 1 , v);
        }
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }
 
    ll query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return 0;
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
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int N , D;
        cin >> N >> D;
        vector<pii> vec;
        vector<int> tmp;
        for(int i = 1; i <= N; ++i){
            int s , a;
            cin >> s >> a;
            if(s < D)continue;
            vec.push_back({s , a});
            tmp.push_back(s);
            tmp.push_back(a);
        }
        N = vec.size();
        if(N == 0){
            cout << 0 << endl;
            continue;
        }
        sort(tmp.begin() , tmp.end());
        tmp.erase(unique(tmp.begin() , tmp.end()) , tmp.end());
        for(int i = 0; i < N; ++i){
            vec[i].x = lower_bound(tmp.begin() , tmp.end() , vec[i].x) - tmp.begin();
            vec[i].y = lower_bound(tmp.begin() , tmp.end() , vec[i].y) - tmp.begin();
        }
        sort(vec.begin() , vec.end() , [&](pii& l , pii& r){
            return l.x + l.y == r.x + r.y ? l.x < r.x : l.x + l.y < r.x + r.y;
        });
        int M = tmp.size();
        max_lazy_tree::build(0 , M - 1 , 1);
        for(int i = N - 1; i >= 0; --i){
            cout << "s = "<< vec[i].x << " a = " << vec[i].y << endl;
            if(vec[i].x >= vec[i].y){
                printf("[%d %d] += 1\n" , vec[i].y , vec[i].x);
                max_lazy_tree::update(vec[i].y , vec[i].x , 0 , M - 1 , 1 , 1);
            }
            ll mx = max_lazy_tree::query(max(vec[i].x + 1 , vec[i].y) , M - 1 , 0 , M - 1 , 1);
            ll bv = max_lazy_tree::query(vec[i].x , vec[i].x , 0 , M - 1 , 1);
            printf("mx= [%d,%d]\n",max(vec[i].x + 1 , vec[i].y) , M - 1);
            DEBUG(mx);
            DEBUG(bv);
            if(mx + 1 > bv){
                printf("[%d %d] += %lld\n",vec[i].x,vec[i].x,mx + 1 - bv);
                max_lazy_tree::update(vec[i].x , vec[i].x , 0 , M - 1 , 1 , mx + 1 - bv);
            }
        }
        cout << max_lazy_tree::tree[1].val << endl;
    }
}
