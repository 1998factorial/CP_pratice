#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
vector<int> g[maxn];
int ans[maxn] , a[maxn] , b[maxn];
void DFS(int v , int c){
    ans[v] = c;
    for(int nv : g[v]){
        if(ans[nv] == -1){
            DFS(nv , c ^ 1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 1; i <= 2 * N; ++i){
        ans[i] = -1;
    }
    for(int i = 1; i <= N; ++i){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for(int i = 1; i <= 2 * N; i += 2){
        if(i + 1 <= 2 * N){
            g[i].push_back(i + 1);
            g[i + 1].push_back(i);
        }
        else{
            g[i].push_back(1);
            g[1].push_back(i);
        }
    }
    for(int i = 1; i <= 2 * N; ++i){
        if(~ans[i])continue;
        DFS(i , 0);
    }
    for(int i = 1; i <= N; ++i){
        cout << ans[a[i]] + 1 << " " << ans[b[i]] + 1 << endl;
    }
}
 