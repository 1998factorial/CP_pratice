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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N),b(N),id(N),win(N,0);
        for(int i = 0; i < N; ++i)cin >> a[i];
        for(int i = 0; i < N; ++i)cin >> b[i];
        for(int i = 0; i < N; ++i)id[i] = i;
        sort(id.begin() , id.end() , [&](auto& l , auto& r){
            return a[l] < a[r];
        });
        vector<int> pre_max(N + 5,0) , suf_min(N + 5,inf32);
        for(int i = 0; i < N; ++i){
            if(i > 0)pre_max[i] = max(pre_max[i - 1] , b[id[i]]);
            else pre_max[i] = max(0 , b[id[i]]);
        }
        for(int i = N - 1; i >= 0; --i){
            suf_min[i] = min(suf_min[i + 1] , b[id[i]]);
        }
        vector<int> f(N + 5 , 0);
        for(int i = 0; i < N; ++i){
            f[i] = max(f[i] , i);
            if(i - 1 >= 0)f[i] = max(f[i] , f[i - 1]);
            if(f[i] >= N - 1){
                win[id[i]] = 1; 
                continue;
            }
            while(1){
                int l = f[i] + 1 , r = N - 1 , v = f[i];
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(suf_min[mid] < pre_max[v]){
                        v = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                if(f[i] == v)break;
                f[i] = v;
            }    
            if(f[i] >= N - 1)win[id[i]] = 1; 

        }
        for(int i : win)cout << i;
        cout << endl;
    }
}