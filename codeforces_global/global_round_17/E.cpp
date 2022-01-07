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
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        int ans = 0;
        // if a sequence is terrible, then it must have a 
        // subsequence of length 3 that is terrible
        for(int i = 0; i < N; ++i){
            // a[cur] - a[i] <= a[nex] - a[cur]
            if(i > 0 && a[i] == a[i - 1])continue;
            int cur = i , val = 1;
            while(cur < N){
                int nex = N , l = cur + 1 , r = N - 1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(a[mid] - a[cur] >= a[cur] - a[i]){
                        nex = mid;
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                if(nex < N){
                    ++val;
                }
                cur = nex;
                if(cur == N - 1)break;
            }
            ans = max(ans , val);
        }
        cout << N - ans << endl;
    }
}