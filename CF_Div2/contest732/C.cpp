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
        vector<int> odd , even;
        for(int i = 0; i < N; ++i){
            if(i & 1)odd.push_back(a[i]);
            else even.push_back(a[i]);
        }
        sort(odd.begin() , odd.end());
        sort(even.begin() , even.end());
        vector<int> ans;
        int i = 0 , j = 0;
        for(int x = 0; x < N; ++x){
            if(x & 1){
                if(ans.empty() || ans.back() <= odd[j]){
                    ans.push_back(odd[j]);
                }
                else{
                    break;
                }
                ++j;
            }
            else{
                if(ans.empty() || ans.back() <= even[i]){
                    ans.push_back(even[i]);
                }
                else{
                    break;
                }
                ++i;
            }
        }
        if(ans.size() >= N){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}   
