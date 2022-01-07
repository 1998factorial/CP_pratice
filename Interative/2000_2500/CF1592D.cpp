#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N;
vector<int> g[1005];
vector<pii> vis;
void DFS(int v , int p){
    for(int nv : g[v]){
        if(nv != p){
            vis.push_back({v , nv});
            DFS(nv , v);
            vis.push_back({v , nv});
        }
    }
}
int ask(set<int> v){
    cout << "? ";
    cout << (int)v.size() << " ";
    for(int i : v)cout << i << " ";
    cout << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i < N; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1 , 1);
    set<int> s;
    for(int i = 1; i <= N; ++i)s.insert(i);
    int max_dis = ask(s);
    int l = 0 , r = vis.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        s.clear();
        for(int i = l; i <= mid; ++i){
            s.insert(vis[i].x);
            s.insert(vis[i].y);
        }
        if(ask(s) >= max_dis){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << "! " << vis[l].x << " " << vis[l].y << endl;
    cout.flush();
} 