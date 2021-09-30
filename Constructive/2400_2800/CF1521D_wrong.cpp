#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(false)
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
const int mod = 1e9 + 7;
int N , deg[maxn] , height[maxn];
vector<int> g[maxn];
vector<pii> add , del;
vector<int> leaf;
void get_height(int v , int p){
    height[v] = 0;
    for(int nv : g[v]){
        if(nv != p){
            get_height(nv , v);
            height[v] = max(height[v] , height[nv]);
        }
    }
    ++height[v];
    debug printf("height[%d] = %d\n" , v , height[v]);
}
void DFS(int v , int p , int is_root){
    if(is_root){
        for(int nv : g[v]){
            if(nv != p){
                DFS(nv , v , 0);
            }
        }
    }
    else{
        if(deg[v] == 1){
            leaf.push_back(v);
        }
        else{
            int max_height = -1 , best = -1;
            for(int nv : g[v]){
                if(nv != p){
                    if(max_height < height[nv]){
                        max_height = height[nv];
                        best = nv;
                    }
                }
            }
            for(int nv : g[v]){
                if(nv != p){
                    if(best != nv){
                        del.push_back({v , nv});
                    }
                    DFS(nv , v , 0);
                }
            }
        }
    }
}
void solve(){
    cin >> N;
    for(int i = 1; i <= N; ++i){
        deg[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i < N; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int root = 1;
    for(; root <= N; ++root)if(deg[root] == 1)break;
    debug cout << "root = " << root << endl;
    get_height(root , root);
    add.clear();
    del.clear();
    leaf.clear();
    DFS(root , root , 1);
    for(int i = 0; i + 1 < (int)leaf.size(); ++i){
        add.push_back({leaf[i] , leaf[i + 1]});
    }
    cout << (int)add.size() << endl;
    assert((int)add.size() == (int)del.size());
    for(int i = 0; i < (int)add.size(); ++i){
        cout << del[i].x << " " << del[i].y << " " << add[i].x << " " << add[i].y << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
} 

/*
1
6
1 2
2 3
2 4
3 5
3 6
exp: 1 operation
out: 2 operation
status: WA
*/