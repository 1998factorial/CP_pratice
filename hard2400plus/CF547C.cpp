#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 2e5 + 10;
const int maxa = 5e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , Q , a[maxn] , on[maxn] , vis[maxa];
ll cnt[maxa];
vector<int> f[maxa];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    int mx = 0;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        mx = max(a[i] , mx);
    }
    for(int i = 2; i <= mx; ++i){
        if(!vis[i]){
            for(int j = i; j <= mx; j += i){
                vis[j] = 1;
                f[j].push_back(i);
            }
        }
    }
    ll total = 0 , nbad = 0;
    while(Q--){
        int x;
        cin >> x;
        if(!on[x]){
            int sz = f[a[x]].size();
            for(int mask = 1; mask < 1 << sz; ++mask){
                int prod = 1;
                for(int i = 0; i < sz; ++i){
                    if(mask >> i & 1){
                        prod *= f[a[x]][i];
                    }
                }
                if(__builtin_popcount(mask) & 1){
                    nbad += cnt[prod];
                }
                else{
                    nbad -= cnt[prod];
                }
            }
            ++total;
            for(int mask = 1; mask < 1 << sz; ++mask){
                int prod = 1;
                for(int i = 0; i < sz; ++i){
                    if(mask >> i & 1){
                        prod *= f[a[x]][i];
                    }
                }
                ++cnt[prod];
            }
        }
        else{
            int sz = f[a[x]].size();
            for(int mask = 1; mask < 1 << sz; ++mask){
                int prod = 1;
                for(int i = 0; i < sz; ++i){
                    if(mask >> i & 1){
                        prod *= f[a[x]][i];
                    }
                }
                --cnt[prod];
            }
            for(int mask = 1; mask < 1 << sz; ++mask){
                int prod = 1;
                for(int i = 0; i < sz; ++i){
                    if(mask >> i & 1){
                        prod *= f[a[x]][i];
                    }
                }
                if(__builtin_popcount(mask) & 1){
                    nbad -= cnt[prod];
                }
                else{
                    nbad += cnt[prod];
                }
            }
            --total;
        }
        cout << total * (total - 1) / 2 - nbad << endl;
        on[x] ^= 1;
    }
}