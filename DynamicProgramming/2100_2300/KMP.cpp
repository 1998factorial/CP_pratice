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
const int maxn = 305;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int N = s.size();
    vector<int> pi(N);
    for(int i = 1; i < N; ++i){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            ++j;
        }
        pi[i] = j;
    }
    for(int i : pi)cout<<i<<" ";
    cout<<endl;
}   