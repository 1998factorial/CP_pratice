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
        int K , N , M;
        cin >> K >> N >> M;
        vector<int> a(N) , b(M);
        for(int i = 0; i < N; ++i)cin >> a[i];
        for(int i = 0; i < M; ++i)cin >> b[i];
        int ok = 1;
        vector<int> ans;
        int i = 0 , j = 0;
        while(i < N && j < M){
            int oka = 0 , okb = 0;
            while(i < N && a[i] <= K){
                oka = 1;
                ans.push_back(a[i]);
                if(a[i] == 0)++K;
                ++i;
            }
            while(j < M && b[j] <= K){
                okb = 1;
                ans.push_back(b[j]);
                if(b[j] == 0)++K;
                ++j;
            }
            if(!oka && !okb){
                ok = 0;
                break;
            }
        }
        while(i < N && a[i] <= K){
            ans.push_back(a[i]);
            if(a[i] == 0)++K;
            ++i;
        }
        while(j < M && b[j] <= K){
            ans.push_back(b[j]);
            if(b[j] == 0)++K;
            ++j;
        }
        if(i < N || j < M)ok = 0;
        if(ok){
            for(int i : ans)cout<<i<<" ";
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}   
