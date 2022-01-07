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
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int a[maxn * 10] , N , xors[maxn * 10] , b[maxn * 10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    int ans = 0;
    for(int bit = 19; bit >= 0; --bit){
        debug cout << "bit = " << bit << endl;
        for(int i = 0; i <= N; ++i){
            xors[i] = 0;
            if(a[i] >> (bit + 1) & 1)b[i] |= (1 << (bit + 1));
        }
        for(int i = 1; i <= N; ++i){
            xors[i] = xors[i - 1] ^ b[i];
        }
        vector<pii> vec;
        {
            int r = 1 , l = 1;
            for(; r <= N; ){
                if((a[r] >> bit & 1) == 0){
                    ++r;
                    l = r;
                    continue;
                }
                l = r;
                while(r + 1 <= N && (a[r + 1] >> bit & 1))++r;
                vec.push_back({l , r});
                ++r;
            }
        }
        for(auto& e : vec){
            int l = e.x , r = e.y;
            debug cout << l << " " << r << endl;
            unordered_map<int , int> L[2];
            L[(l - 1) & 1][xors[l - 1]] = l - 1;
            for(int i = l; i <= r; ++i){
                int v = xors[i];
                debug cout << "v = " << v << endl;
                if(L[i & 1].find(v) != L[i & 1].end()){
                    debug cout << "len = " << i - L[(i + 1) & 1][v] << endl;
                    ans = max(ans , i - L[i & 1][v]);
                }
                if(L[i & 1].find(v) == L[i & 1].end())L[i & 1][v] = i;
            }
        }
    }
    cout << ans << endl;
} 