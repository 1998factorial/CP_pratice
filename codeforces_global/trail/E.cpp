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
        int good = 0;
        for(int i = 0; i < N; ++i){
            if(i - 1 >= 0 && a[i] == a[i - 1])continue;
            int val = 1 , cur = i;
            while(cur < N){
                int l = cur + 1 , r = N - 1 , nex = N;
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
                cur = nex;
                if(cur < N)++val;
            }
            good = max(good , val);
        }
        cout << N - good << endl;
    }
}