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
const int maxv = 1e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for(int i = 1; i <= N; ++i)cin >> a[i];
        int ok = 1;
        for(int i = 1; i <= N; ++i){
            if(i & 1){
                if((a[i] & 1) == 0){
                    ok = 0;
                }
            }
        }
        if(!ok){
            cout << -1 << endl;
            continue;
        }
        //reverse(a.begin() + 1 + 1 , a.begin() + 1 + 3);
        //for(int i = 1; i <= N; ++i)cout << a[i] << " ";
        //cout << endl;
        vector<int> ans;
        for(int i = N; i > 1; i -= 2){
            if(a[i] == i && a[i - 1] == i - 1)continue;
            // we can get i - 1 and i in place in 5 steps
            int pos = 1;
            for(int j = 1; j <= i; ++j){
                if(a[j] == i){
                    pos = j;
                    break;
                }
            }
            ans.push_back(pos);
            reverse(a.begin() + 1 , a.begin() + 1 + pos);
            pos = 1;
            for(int j = 1; j <= i; ++j){
                if(a[j] == i - 1){
                    pos = j - 1;
                    break;
                }
            }
            ans.push_back(pos);
            reverse(a.begin() + 1 , a.begin() + 1 + pos);
            pos += 2;
            ans.push_back(pos);
            reverse(a.begin() + 1 , a.begin() + 1 + pos);
            ans.push_back(3);
            reverse(a.begin() + 1 , a.begin() + 1 + 3);
            ans.push_back(i);
            reverse(a.begin() + 1 , a.begin() + 1 + i);
        }
        cout << ans.size() << endl;
        for(int i : ans)cout << i << " ";
        cout << endl;
    }
} 