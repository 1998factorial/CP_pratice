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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
ll mod = 1e9 + 7;
ll fac[maxn];
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    x += y;
    if(x >= mod)x -= mod;
    return x;
}
ll sub(ll x , ll y){
    x -= y;
    if(x < 0)x += mod;
    return x;
}
ll qpow(ll x , ll n){
    ll ans = 1;
    while(n){
        if(n & 1)ans = mul(ans , x);
        x = mul(x , x);
        n /= 2;
    }
    return ans;
}
ll inverse(ll x){
    return qpow(x , mod - 2);
}
ll C(int n , int m){
    if(n < 0 || m < 0 || n < m)return 0;
    return mul(fac[n] , mul(inverse(fac[n - m]) , inverse(fac[m])));
}
const int maxv = 65555;
vector<int> g[maxv];
set<int> s[maxv];
int N , perm[maxv] , colour[maxv];
void find_permutation(){
    // construct the permuted hypercube
    vector<bool> used(1 << N);
    for(int i = 0; i < (1 << N); ++i)perm[i] = -1;
    // let the first vertex in the permutation be 0
    perm[0] = 0;
    used[0] = true;
    // a permuted hypercube is also isomorphic to a simple hypercube
    // so each node is differ in one bit to it's neighbours
    for(int u = 1; u < (1 << N); ++u){
        // build the permutation in increasing order
        vector<int> S;
        for(int i = 0; i < N; ++i){
            int v = u ^ (1 << i);
            if(v < u){
                S.push_back(v);
            }
        }
        if(S.size() == 1){
            // meaning u is a power of 2 and v is 0
            int v = perm[S[0]];
            for(int i = 0; i < g[v].size(); ++i){
                int w = g[v][i];
                if(used[w])continue;
                perm[u] = w;
                used[w] = true;
                break;
            }
        }
        else{
            // not a power of 2
            int v = perm[S[0]];
            int x = perm[S[1]];
            // now v and x differs by exactly 2 bits
            for(int i = 0; i < g[v].size(); ++i){
                int w = g[v][i];
                if(used[w])continue;
                if(s[w].find(x) == s[w].end())continue;
                perm[u] = w;
                used[w] = true;
                break;
            }
        }
    }
    for(int i = 0; i < (1 << N); ++i){
        cout << perm[i] << " ";
    }
    cout << endl;
}
void find_colouring(){
    if(N != 1 && N != 2 && N != 4 && N != 8 && N != 16){
        cout << -1 << endl;
        return;
    }
    for(int u = 0; u < (1 << N); ++u){
        colour[u] = 0;
        for(int i = 0; i < N; ++i){
            if((u >> i) & 1){
                colour[u] ^= i;
            }
        }
    }
    vector<int> ans(1 << N);
    for(int i = 0; i < (1 << N); ++i){
        ans[perm[i]] = colour[i];
    }
    for(int i = 0; i < (1 << N); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < (1 << N); ++i){
            g[i].clear();
            s[i].clear();
        }
        for(int i = 1; i <= N * (1 << (N - 1)); ++i){
            int u , v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            s[u].insert(v);
            s[v].insert(u);
        }
        find_permutation();
        find_colouring();
    }
}   