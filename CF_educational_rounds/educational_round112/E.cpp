#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxn = 1e6 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , M;
vector<array<int , 3>> intervals;
struct min_lazy_tree{
 
    struct node{
        int val , lazy;
        node(){}
        node(int v , int z) : val(v) , lazy(z) {}
    };
 
    node tree[maxn * 5];
 
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
        if(l.val < r.val){
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
 
    void update(int l , int r , int x , int y , int id , int v){ // support range update
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
 
    int query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return -inf32;
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
        return min(
            query(l , r , x , mid , id << 1) ,
            query(l , r , mid + 1 , y , id << 1 | 1)
        );
    }
 
} T;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        int l , r , w;
        cin >> l >> r >> w;
        r--;
        intervals.push_back({w , l , r});
    }
    --M;
    T.build(1 , M , 1);
    sort(intervals.begin() , intervals.end());
    int ans = 1e6;
    int j = 0;
    for(int i = 0; i < N; ++i){
        T.update(intervals[i][1] , intervals[i][2] , 1 , M , 1 , 1);
        for(;T.tree[1].val;){
            ans = min(ans , -intervals[j][0] + intervals[i][0]);
            T.update(intervals[j][1] , intervals[j][2] , 1 , M , 1 , -1);
            ++j;
        }
    }
    cout << ans << endl;
} 