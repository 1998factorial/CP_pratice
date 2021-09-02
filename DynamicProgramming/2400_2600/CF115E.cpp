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
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N , M , cost[maxn];
vector<pii> race[maxn];
ll dp[maxn];
ll cal(int l , int r){
    ll neg = 0 , pos = 0;
    for(int i = l; i <= r; ++i){
        neg -= cost[i];
    }
    for(int i = r; i >= l; --i){
        for(auto [b , v] : race[i]){
            if(b >= l){
                pos += v;
            }
        }
    }
    return pos + neg;
}
struct max_lazy_tree{

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
            tree[id].val = -inf64;
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
        if(l > r || x > y || y < l || x > r)return -inf64;
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

} T;
// dp[i] = max{dp[i - 1] , max{dp[j] + bene(j + 1 , i) - cost(j + 1 , i)}}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)cin >> cost[i];
    for(int i = 1; i <= M; ++i){
        int l , r , v;
        cin >> l >> r >> v;
        race[r].emplace_back(l , v);
    }
    T.build(0 , N , 1);
    T.update_point(0 , 0 , N , 1 , 0);
    for(int i = 1; i <= N; ++i){
        dp[i] = max(dp[i] , dp[i - 1]);
        T.update(0 , i - 1 , 0 , N , 1 , -cost[i]);
        for(auto [l , v] : race[i]){
            T.update(0 , l - 1 , 0 , N , 1 , v);
        }
        dp[i] = max(dp[i] , T.query(0 , i , 0 , N , 1));
        T.update_point(i , 0 , N , 1 , dp[i]);
    }
    cout << dp[N] << endl;
} 