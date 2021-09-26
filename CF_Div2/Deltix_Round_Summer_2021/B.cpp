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
const int maxn = 2e5 + 10;
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
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        int even = 0 , odd = 0;
        for(int i : a){
            if(i & 1)++odd;
            else ++even;
        }
        //cout << "even = " << even << endl;
        //cout << "N + 1 / 2 = " << (N + 1) / 2 << endl;
        if(max(odd , even) > (N + 1) / 2){
            cout << -1 << endl;
            continue;
        }
        vector<int> pos;
        if(odd == (N + 1) / 2){
            for(int i = 0; i < N; ++i){
                if(a[i] & 1)pos.push_back(i);
            }
        }
        else if(even == (N + 1) / 2){
            for(int i = 0; i < N; ++i){
                if((a[i] & 1) == 0)pos.push_back(i);
            }
        }
        int cnt = 0;
        if(N % 2 == 0){
            int c1 = 0 , c2 = 0;
            for(int i = 0; i < pos.size(); ++i){
                c1 += abs(pos[i] - 2 * i);
                c2 += abs(pos[i] - (2 * i + 1));
            }
            cnt = min(c1 , c2);
        }
        else{
            for(int i = 0; i < pos.size(); ++i){
                //cout << pos[i] << " ";
                cnt += abs(2 * i - pos[i]);
            }
        }
        //cout << "end \n";
        cout << cnt << endl;
    }
} 