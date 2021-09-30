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
int N , deg[maxn] , fa[maxn];
vector<int> g[maxn];
vector<pii> del , add; 
map<pii , int> deleted;
/*
    the problem is the same as : 
    "minimal number of edges we can erase to make the tree into a forest of chains"
    solve for each subtree
    solve for each child first
    when come back to v, all child's subtree are chain
    so it is always not worse to erase (v , v's father) when needed
*/
void DFS(int v , int p){
    for(int nv : g[v]){
        if(nv != p){
            DFS(nv , v);
        }
    }
    if(deg[v] > 2){
        if(p != -1 && deleted[{min(v , p) , max(v , p)}] == 0){
            --deg[v];
            --deg[p];
            deleted[{min(v , p) , max(v , p)}] = 1;
            del.push_back({min(v , p) , max(v , p)});
        }
        for(int nv : g[v]){
            if(deg[v] <= 2)break;
            if(nv != p && deleted[{min(v , nv) , max(v , nv)}] == 0){
                --deg[v];
                --deg[nv];
                deleted[{min(nv , v) , max(nv , v)}] = 1;
                del.push_back({min(nv , v) , max(nv , v)});
            }
        }
    }
}
void init(){
    for(int i = 1; i <= N; ++i)fa[i] = i;
    for(int i = 1; i <= N; ++i){
        deg[i] = 0;
        g[i].clear();
    }
    del.clear();
    add.clear();
    deleted.clear();
}
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y){
    x = find(x); y = find(y); if(x != y)fa[x] = y;
}
void solve(){
    cin >> N;
    init();
    for(int i = 1; i < N; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    DFS(1 , -1);
    cout << (int)del.size() << endl;
    for(int i = 1; i <= N; ++i){
        for(int j : g[i]){
            if(deleted[{min(i , j) , max(i , j)}] == 0){
                merge(i , j);
            }
        }
    }
    vector<pii> leaf;
    for(int i = 1; i <= N; ++i){
        assert(deg[i] <= 2);
        if(deg[i] <= 1){
            leaf.push_back({find(i) , i});
        }
    }
    debug{
        for(int i = 1; i <= N; ++i){
            printf("f[%d] = %d\n" , i , fa[i]);
            printf("deg[%d] = %d\n" , i , deg[i]);
        }
    }
    sort(leaf.begin() , leaf.end());
    for(int i = 0; i + 1 < (int)leaf.size(); ++i){
        if(find(leaf[i].x) != find(leaf[i + 1].x)){
            add.push_back({leaf[i].y , leaf[i + 1].y});
            ++deg[leaf[i].y];
            ++deg[leaf[i + 1].y];
            merge(leaf[i].y , leaf[i + 1].y);
        }
    }
    debug {
        cout << "break\n\n\n";
        for(int i = 1; i <= N; ++i){
            printf("f[%d] = %d\n" , i , fa[i]);
            printf("deg[%d] = %d\n" , i , deg[i]);
        }
    }
    assert((int)del.size() == (int)add.size());
    for(int i = 0; i < (int)del.size(); ++i){
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
*/