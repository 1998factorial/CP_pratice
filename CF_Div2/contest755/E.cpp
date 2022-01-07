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
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;

struct min_lazy_tree{
    struct node{
        ll val , lazy , cnt;
        node(){}
        node(ll v , ll z , ll x) : val(v) , lazy(z) , cnt(x) {}
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
        node ret(0 , 0 , 0);
        ret.val = min(l.val , r.val);
        if(ret.val == l.val)ret.cnt += l.cnt;
        if(ret.val == r.val)ret.cnt += r.cnt;
        return ret;
    }
 
    void build(int l , int r , int id , const vector<ll>& vec){
        if(l > r)return;
        if(l == r){
            tree[id].val = vec[l];
            tree[id].lazy = 0;
            tree[id].cnt = 1;
        }
        else{
            int mid = (l + r) >> 1;
            build(l , mid , id << 1 , vec);
            build(mid + 1 , r , id << 1 | 1 , vec);
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
 
    node query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return node(inf64 , 0 , 0);
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

    int find_index(int l , int r , int id){
        if(l > r)return inf32;
        push_down(l , r , id);
        if(tree[id].val >= 0)return inf32;
        if(l == r){
            return l;
        }
        int mid = (l + r) >> 1;
        if(tree[id << 1].val < 0){
            return find_index(l , mid , id << 1);
        }
        else if(tree[id << 1 | 1].val < 0){
            return find_index(mid + 1 , r , id << 1 | 1);
        }
        return inf32;
    }

} even , odd;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N);
        vector<ll> c(N) , o , e;
        for(int i = 0; i < N; ++i){
            cin >> a[i];
            c[i] = a[i];
            if(i > 0)c[i] -= c[i - 1];
            if(i & 1)o.push_back(c[i]);
            if(!(i & 1))e.push_back(c[i]);
        }
        even.build(0 , e.size() - 1 , 1 , e);
        odd.build(0 , o.size() - 1 , 1 , o);
        ll ans = 0;
        for(int i = 0; i < N; ++i){
            int even_bound = even.find_index(0 , e.size() - 1 , 1); 
            int odd_bound = odd.find_index(0 , o.size() - 1 , 1);
            even_bound *= 2;
            odd_bound *= 2;
            odd_bound += 1;
            int index = min(N , min(even_bound , odd_bound));
            index -= 1;
            debug{
                DEBUG(odd_bound/2);
                DEBUG(even_bound/2);
                DEBUG(index);
            }
            min_lazy_tree::node E = even.query((i & 1) ? (i + 1) / 2 : i / 2 , (index & 1) ? index / 2 : index / 2 , 0 , e.size() - 1 , 1);
            min_lazy_tree::node O = odd.query((i & 1) ? i / 2 : i / 2 , (index & 1) ? index / 2 : (index - 1) / 2 , 0 , o.size() - 1 , 1);
            if(E.val == 0)ans += E.cnt;
            if(O.val == 0)ans += O.cnt;
            if(i & 1){
                even.update((i + 1) / 2 , e.size() - 1 , 0 , e.size() - 1 , 1 , a[i]);
                odd.update_point(i / 2 , 0 , o.size() - 1 , 1 , inf32);
                odd.update(i / 2 , o.size() - 1 , 0 , o.size() - 1 , 1 , -a[i]);
            }
            else{
                even.update_point(i / 2 , 0 , e.size() - 1 , 1 , inf32);
                even.update(i / 2 , e.size() - 1 , 0 , e.size() - 1 , 1 , -a[i]);
                odd.update(i / 2 , o.size() - 1 , 0 , o.size() - 1 , 1 , a[i]);
            }
        }
        cout << ans << endl;
    }
}