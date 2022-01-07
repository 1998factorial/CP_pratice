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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N;
namespace lazy_min_tree {
    #define long long ll
    const int maxn = 3e5 + 10;
    const ll INF = 1e18 + 10;
    struct node{
        ll val , freq , lazy;
        node(){}
        node(ll v , ll f , ll z) : val(v) , freq(f) , lazy(z) {}
    } tree[maxn * 4];
 
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
        node ret(INF , 0 , 0);
        ret.val = min(l.val , r.val);
        if(ret.val == l.val){
            ret.freq += l.freq;
        }
        if(ret.val == r.val){
            ret.freq += r.freq;
        }
        return ret;
    }
 
    void build(int l , int r , int id){
        if(l > r)return;
        if(l == r){
            tree[id].val = 0;
            tree[id].lazy = 0;
            tree[id].freq = 1;
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
 
    node query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return node(INF , 0 , 0);
        push_down(x , y , id);
        if(l <= x && y <= r){
            return tree[id];
        }
        int mid = (x + y) >> 1;
        if(r <= mid){
            return query(l , r , x , mid , id << 1);
        }
        if(l > mid){
            return query(l , r , mid + 1 , y , id << 1 | 1);
        }
        return merge(
            query(l , r , x , mid , id << 1) ,
            query(l , r , mid + 1 , y , id << 1 | 1)
        );
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N; 
    vector<int> a(N + 1) , pos(N + 1 , -1) , cnt(N + 1 , 0);
    lazy_min_tree::build(1 , N , 1);
    a[0] = inf32;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    ll ans = 0;
    vector<int> mono_stack; mono_stack.push_back(0);
    for(int r = 1 , l = 1; r <= N; ++r){
        pos[a[r]] = r;
        ++cnt[a[r]];
        while(l <= r && cnt[a[r]] > 1){ // use 2 pointers to maintain window of distinct element
            --cnt[a[l]];
            ++l;
        }
        lazy_min_tree::update(1 , r , 1 , N , 1 , 1ll * -1);
        lazy_min_tree::update(r , r , 1 , N , 1 , (ll)a[r]);
        // now we focus on [l , pos[1]]
        // we need to find the number of x in [l , pos[1]] 

        // maintain a strictly decreasing stack
        while(!mono_stack.empty() && a[r] > a[mono_stack.back()]){
            int x = mono_stack.back();
            mono_stack.pop_back();
            lazy_min_tree::update(mono_stack.back() + 1 , x , 1 , N , 1 , a[r] - a[x]);
        }
        mono_stack.push_back(r);
        if(pos[1] >= l){
            lazy_min_tree::node v = lazy_min_tree::query(l , pos[1] , 1 , N , 1);
            if(v.val == 0){
                ans += v.freq;
            }
        }
    }
    cout << ans << endl;
} 

/*
 
*/