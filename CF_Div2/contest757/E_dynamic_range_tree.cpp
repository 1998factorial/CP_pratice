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
const int maxv = 2e7 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 1;
ll add(ll x , ll y){
    return (x + y) % mod;
}
namespace dynamic_range_tree {
    #define ll long long
    #define maxn 100010
    #define ls(x) t[x].lson
    #define rs(x) t[x].rson
    struct node{
        int lson , rson , l , r , lazy;
    } t[maxn * 128];
    int tot = 0;
    void push_down(int id , int l , int r){
        int mid = (l + r) >> 1;
        if(t[id].lson == 0){
            t[++tot] = {0 , 0 , l , mid , 0};
            t[id].lson = tot;
        }
        if(t[id].rson == 0){
            t[++tot] = {0 , 0 , mid + 1 , r , 0};
            t[id].rson = tot;
        }
        if(t[id].lazy){
            t[ls(id)].lazy += t[id].lazy;
            t[ls(id)].l += t[id].lazy;
            t[ls(id)].r += t[id].lazy;
            t[rs(id)].lazy += t[id].lazy;
            t[rs(id)].l += t[id].lazy;
            t[rs(id)].r += t[id].lazy;
            t[id].lazy = 0;
        }
    }
    void push_up(int id){
        t[id].l = t[ls(id)].l;
        t[id].r = t[rs(id)].r;
    }
    void add(int id , int x , int y , int l , int r , int v){
        if(x > r || y < l)return;
        if(l <= x && y <= r){
            t[id].l += v;
            t[id].r += v;
            t[id].lazy += v;
            return;
        }
        int mid = (x + y) >> 1;
        push_down(id , x , y);
        add(ls(id) , x , mid , l , r , v);
        add(rs(id) , mid + 1 , y , l , r , v);
        push_up(id);
    }
    // find the largest index whose value is <= val
    int query_index(int id , int l , int r , int val){
        if(t[id].l > val)return l - 1;
        if(t[id].r <= val)return r;
        if(l == r)return l;
        int mid = (l + r) >> 1;
        if(ls(id)){
            push_down(id , l , r);
            return t[rs(id)].l <= val ? query_index(rs(id) , mid + 1 , r , val) : query_index(ls(id) , l , mid , val);
        }
        return l + val - t[id].l;
    }   
    // find the value on position pos
    int query(int id , int l , int r , int pos){
        if(l == r)return t[id].l;
        int mid = (l + r) >> 1;
        if(ls(id)){
            push_down(id , l , r);
            return pos <= mid ? query(ls(id) , l , mid , pos) : query(rs(id) , mid + 1 , r , pos);
        }
        return t[id].l + pos - l;
    }
}
int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ans = 0;
    cin >> N;
    dynamic_range_tree::tot++;
    dynamic_range_tree::t[dynamic_range_tree::tot] = {0 , 0 , 0 , mod , 0};
    for(int i = 1; i <= N; ++i){
        int sz , T;
        cin >> T >> sz;
        int pos1 = dynamic_range_tree::query_index(1 , 0 , mod , T - 1);
        int pos2 = dynamic_range_tree::query_index(1 , 0 , mod , T) + 1;
        dynamic_range_tree::add(1 , 0 , mod , 0 , pos1 , 1);
        dynamic_range_tree::add(1 , 0 , mod , pos2 , mod , -1);
        for(int j = 0; j < sz; ++j){
            int x;
            cin >> x;
            x = add(x , ans);
            ans = dynamic_range_tree::query(1 , 0 , mod , x);
            cout << ans << endl;
        }
    }
}