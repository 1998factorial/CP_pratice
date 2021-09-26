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
        for(int i = 0; i < N; ++i){
            cin >> a[i];
        }
        vector<pii> vec;
        int pre = 0 , cur = 0;
        for(; cur < N; ++cur){
            if(cur - 1 >= 0 && a[cur] == a[cur - 1]){
                vec.push_back({pre , cur - 1});
                pre = cur;
            }
        }
        if(pre <= N - 1)vec.push_back({pre , N - 1});
        vector<int> cnt(N + 1);
        for(int i : a){
            ++cnt[i];
        }
        int bad = 0;
        for(int i = 1; i <= N; ++i){
            if(cnt[i] > (N + 1) / 2){
                bad = 1;
            }
        }
        if(bad){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1; i <= N; ++i)cnt[i] = 0;
        for(auto e : vec){
            ++cnt[a[e.x]];
            ++cnt[a[e.y]];
        }
        int max_cnt = 0 , nsegments = (int)vec.size();
        for(int i = 1; i <= N; ++i){
            max_cnt = max(max_cnt , cnt[i]);
        }
        if(max_cnt <= nsegments + 1){
            cout << (int)nsegments - 1 << endl;
        }
        else{
            int additional = max_cnt - (nsegments + 1);
            cout << nsegments - 1 + additional << endl;
        }
    }
} 
