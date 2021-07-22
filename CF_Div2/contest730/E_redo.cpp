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
        int nV = 1 << N;
        vector<vector<int>> g(nV , vector<int>());
        vector<set<int>> s(nV , set<int>()); 
        for(int i = 0; i < N * (1 << (N - 1)); ++i){
            int u , v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            s[u].insert(v);
            s[v].insert(u);
        }
        vector<int> perm(nV , -1) , used(nV , 0);
        perm[0] = 0;
        used[0] = 1;
        for(int i = 0; i < g[0].size(); ++i){
            perm[(1 << i)] = g[0][i];
            used[g[0][i]] = 1;
        }
        for(int i = 3; i < nV; ++i){
            if(~perm[i])continue;
            vector<int> prev;
            for(int j = 0; j < N; ++j){
                int pv = i ^ (1 << j);
                if(pv < i){
                    prev.push_back(pv);
                }
            }
            for(int v : g[perm[prev[0]]]){
                if(used[v])continue;
                if(s[perm[prev[1]]].count(v) == 0)continue;
                used[v] = 1;
                perm[i] = v;
                break;
            }
        }
        for(int i : perm)cout << i << " ";
        cout << endl;
        if(N != 1 && N != 2 && N != 4 && N != 8 && N != 16){
            cout << -1 << endl;
        }
        else{
            vector<int> colour(nV , 0) , tmp(nV , 0);
            for(int i = 0; i < nV; ++i){
                for(int j = 0; j < N; ++j){
                    if(i >> j & 1)tmp[i] ^= j;
                }
            }
            for(int i = 0; i < nV; ++i){
                colour[perm[i]] = tmp[i];
            }
            for(int i : colour)cout << i << " ";
            cout << endl;
        }
    }
}   