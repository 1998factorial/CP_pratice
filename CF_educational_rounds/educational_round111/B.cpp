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
        int N , a , b;
        string s;
        cin >> N >> a >> b;
        cin >> s;
        if(b > 0){
            cout << N * (a + b) << endl;
        }
        else{
            vector<int> cnt(2);
            ++cnt[s[0] - '0'];
            for(int i = 1; i < N; ++i){
                if(s[i] != s[i - 1]){
                    ++cnt[s[i] - '0'];
                }
            }
            cout << N * a + b * min(cnt[0] + 1 , cnt[1] + 1) << endl;
        }
    }
}   
// easy greedy