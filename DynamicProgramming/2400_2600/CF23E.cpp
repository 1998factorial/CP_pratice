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
/*
    dp[v][i] = maximal product of v's subtree (not including v) if v's connected component size = i 
    ans[v] = the maximal product of v's subtree (including v's connected component)
    iterate v's child nv, 
    if we keep edge (v , nv) : dp[v][i + j] = max{dp[v][i] * dp[nv][j]}
    if we cut edge (v , nv) : dp[v][i] = max(dp[v][i] , dp[v][i] * ans[nv])
    ans[v] = max{dp[v][i] * i}
*/
struct big_int{
    short a[205] , t;
    big_int(){
        memset(a , 0 , sizeof(a));
        t = 1;
    }
    big_int(ll x){
        memset(a , 0 , sizeof(a));
        t = 0;
        while(x){
            a[++t] = x % 10;
            x /= 10;
        }
    }
    short &operator [](int x){
        return a[x];
    }
    void push_up(){
        for(int i = 1; i <=  t; ++i){
            if(a[i] > 9){
                a[i + 1] += a[i] / 10;
                a[i] %= 10;
                if(i == t)++t;
            }
        }
        while(t > 1 && a[t] == 0)--t;
    }
    big_int operator * (int x) {
        big_int ret;
        ret.t = t;
        for(int i = 1; i <= t; ++i){
            ret.a[i] = a[i] * x;
        }
        ret.push_up();
        return ret;
    }
    big_int operator * (big_int& B) {
        big_int ret;
        ret.t = t + B.t - 1;
        for(int i = 1; i <= t; ++i){
            for(int j = 1; j <= B.t; ++j){
                ret.a[i + j - 1] += a[i] * B.a[j];
            }
        }        
        ret.push_up();
        return ret;
    }
    big_int operator + (big_int& B) {
        big_int ret;
        ret.t = max(t , B.t);
        int carry = 0;
        for(int i = 1; i <= max(t , B.t); ++i){
            ret.a[i] = a[i] + B.a[i];
        }      
        ret.push_up();
        return ret;
    }
    bool operator < (const big_int& B) const {
        if(t < B.t)return 1;
        if(t > B.t)return 0;
        for(int i = t; i >= 1; --i){
            if(a[i] < B.a[i])return 1;
            if(a[i] > B.a[i])return 0;
        }
        return 0;
    }
    bool operator > (const big_int& B) const {
        return !(*this < B); 
    }
    void show(){
        for(int i = t; i >= 1; --i){
            cout << a[i];
        }
    }
};
big_int dp[705][705] , ans[705];
vector<int> g[705];
int N , sz[705];


void DFS(int v , int p){
    sz[v] = 1;
    dp[v][1] = big_int(1ll);
    ans[v] = big_int(0ll);
    for(int nv : g[v]){
        if(nv == p)continue;
        DFS(nv , v);
        for(int i = sz[v]; i >= 1; --i){
            // we don't cut (v , nv)
            for(int j = sz[nv]; j >= 1; --j){
                dp[v][i + j] = max(dp[v][i + j] , dp[v][i] * dp[nv][j]);
            }
            // we cut (v , nv)
            dp[v][i] = max(dp[v][i] , dp[v][i] * ans[nv]);
        }
        sz[v] += sz[nv];
    }
    for(int i = 1; i <= sz[v]; ++i){
        big_int val = big_int(i);
        ans[v] = max(ans[v] , dp[v][i] * val);
    }
    //cout << "ans[" << v << "] = "; ans[v].show(); cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N - 1; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1 , 1);
    ans[1].show(); 
    cout << endl;
}