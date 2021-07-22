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
const int inf32 = 1e9 + 10000;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int N = s.size();
        int ok = 1;
        vector<int> cnt(N);
        for(int i = 0; i < N; ++i){ 
            if(s[i] - 'a' > N - 1){
                ok = 0;
                break;
            }
            else{
                cnt[s[i] - 'a']++;
            }
        }
        for(int i = 0; i < N; ++i){
            if(cnt[i] != 1)ok = 0;
        }
        if(ok){
            vector<int> pos(N);
            for(int i = 0; i < N; ++i){
                pos[s[i] - 'a'] = i;
            }
            for(int i = 0; i < N - 1; ++i){
                int l = min(pos[i] , pos[i + 1]);
                int r = max(pos[i] , pos[i + 1]);
                for(int j = l + 1; j < r; ++j){
                    if(s[j] - 'a' > i)ok = 0;
                }
            }
            if(ok)
            cout << "YES" << endl;
            else
            cout << "NO" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}   
