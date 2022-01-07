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
const int maxn = 4e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int base = 4e5 + 10;
namespace lazy_min_tree {
    #define long long ll
    const int maxn = 1e6 + 10;
    const ll INF = 1e18 + 10;
    struct node{
        ll val , lazy;
        node(){}
        node(ll v , ll z) : val(v) , lazy(z) {}
    } tree[maxn * 4];
    ll a[maxn];
    int N;
 
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
            tree[id].val = a[l];
            tree[id].lazy = 0;
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
 
    ll query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return INF;
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
    void init(const vector<ll>& b){
        N = b.size();
        for(int i = 0; i < N; ++i)a[i] = b[i];
        build(0 , N - 1 , 1);
    }
}
namespace fenwick {
    const int maxn = 1e6 + 10;
    int tree[maxn * 4] , N;
    int query(int pos){
        int ans = 0;
        while(pos){
            ans += tree[pos];
            pos -= pos & (-pos);
        }
        return ans;
    }
    void update(int pos , int v){
        while(pos <= N){
            tree[pos] += v;
            pos += pos & (-pos);
        }
    }
    void init(int n){
        N = n;
        for(int i = 0; i <= N * 4; ++i){
            tree[i] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , M;
        cin >> N >> M;
        vector<int> a(N) , b(M) , tmp;
        for(int i = 0; i < N; ++i){
            cin >> a[i];
            tmp.push_back(a[i]);
        }
        for(int i = 0; i < M; ++i){
            cin >> b[i];
            tmp.push_back(b[i]);
        }
        sort(tmp.begin() , tmp.end());
        sort(b.begin() , b.end());
        int total = unique(tmp.begin() , tmp.end()) - tmp.begin();
        tmp.erase(tmp.begin() + total , tmp.end());
        for(int i = 0; i < N; ++i){
            a[i] = lower_bound(tmp.begin() , tmp.end() , a[i]) - tmp.begin() + 1;
        }
        for(int i = 0; i < M; ++i){
            b[i] = lower_bound(tmp.begin() , tmp.end() , b[i]) - tmp.begin() + 1;
        }
        fenwick::init(total);
        // calculate # of inversions in a first
        ll ans = 0;
        for(int i = 0; i < N; ++i){
            ans += fenwick::query(total) - fenwick::query(a[i]);
            fenwick::update(a[i] , 1);
        }
        vector<ll> prefix(N + 1) , suffix(N + 1) , ansB0(N + 1);
        fenwick::init(total);
        for(int i = 1; i <= N; ++i){
            // if we put b[0] after a[i] , # of inversions in our prefix = ?
            fenwick::update(a[i - 1] , 1);
            prefix[i] = fenwick::query(total) - fenwick::query(b[0]);
        }
        fenwick::init(total);
        for(int i = N - 1; i >= 0; --i){
            // if we put b[0] after a[i] , # of inversions in ouf suffix = ?
            fenwick::update(a[i] , 1);
            suffix[i] = fenwick::query(b[0] - 1);
        }
        for(int i = 0; i <= N; ++i){
            ansB0[i] = suffix[i] + prefix[i];
        }
        // now we deduce answer for b[x] from b[x - 1]
        lazy_min_tree::init(ansB0);
        vector<int> pos[total + 1];
        for(int i = 0; i < N; ++i){
            pos[a[i]].push_back(i + 1); // index start with 1
        }
        for(int i = 1; i < M; ++i){
            ans += lazy_min_tree::tree[1].val;
            // for each b[i - 1] <= a[j] <= b[i]
            for(int j = b[i - 1]; j < b[i]; ++j){
                for(int k : pos[j]){
                    lazy_min_tree::update(0 , k - 1 , 0 , N , 1 , 1);
                }
            }
            for(int j = b[i - 1] + 1; j <= b[i]; ++j){
                for(int k : pos[j]){
                    lazy_min_tree::update(k , N , 0 , N , 1 , -1);
                }
            }
        }
        ans += lazy_min_tree::tree[1].val;
        cout << ans << endl;
    }
} 