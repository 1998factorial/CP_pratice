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
vector<int> g[maxn] , X[maxn] , Y[maxn];
int ans[maxn];
void DFS(int v , int c){
    ans[v] = c;
    for(int nv : g[v]){
        if(~ans[nv])continue;
        DFS(nv , c ^ 1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , mx = 0 , my = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int x , y;
        cin >> x >> y;
        mx = max(mx , x);
        my = max(my , y);
        X[x].push_back(i);
        Y[y].push_back(i);
    }
    for(int i = 1; i <= mx; ++i){
        sort(X[i].begin() , X[i].end());
        for(int j = 0; j + 1 < X[i].size(); j += 2){
            int v = X[i][j] , u = X[i][j + 1];
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }
    for(int i = 1; i <= my; ++i){
        sort(Y[i].begin() , Y[i].end());
        for(int j = 0; j + 1 < Y[i].size(); j += 2){
            int v = Y[i][j] , u = Y[i][j + 1];
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }
    for(int i = 1; i <= N; ++i)ans[i] = -1;
    for(int i = 1; i <= N; ++i){
        if(~ans[i])continue;
        DFS(i , 0);
    }
    for(int i = 1; i <= N; ++i){
        if(ans[i])cout << "b";
        else cout << "r";
    }
    cout << endl;
}
 