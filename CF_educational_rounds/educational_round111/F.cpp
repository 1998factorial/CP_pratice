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
const int maxx = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , Q , start , D;
int a[maxn] , fa[maxn] , ncomponent , minK[maxn];
map<int , int> id;
vector<int> component[maxn];
set<int> all_vertices;
vector<pii> MST[maxn];
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y){
    // merge component x and component y
    x = find(x);
    y = find(y);
    if(component[x].size() < component[y].size()){
        swap(x , y);
    }
    for(int v : component[y]){
        fa[v] = x;
        component[x].push_back(v);
    }
    component[y].clear();
}
void DFS(int v , int p , int w){
    minK[v] = w;
    for(auto& e : MST[v]){  
        int nv = e.x , nw = e.y;
        if(nv != p){
            DFS(nv , v , max(w , nw));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q >> start >> D;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        id[a[i]] = i;
        fa[i] = i;
        component[i].push_back(i);
        all_vertices.insert(a[i]);
        minK[i] = inf32;
    }
    ncomponent = N;
    int round = 0;
    while(ncomponent > 1){
        ++round;
        vector<array<int , 3>> edges_this_round;
        for(int i = 1; i <= N; ++i){
            if(component[i].empty())continue;
            for(int j : component[i]){
                all_vertices.erase(a[j]);
            }
            array<int , 3> min_edge = {-1 , -1 , inf32};
            for(int j : component[i]){
                for(int k : {-1 , 1}){
                    for(int t : {-1 , 1}){
                        // find the closest vertex to t * a[j] + k * D
                        auto it = all_vertices.lower_bound(t * a[j] + k * D);
                        if(it != all_vertices.end()){
                            int w = abs(D - abs(a[j] - *it));
                            if(w < min_edge[2]){
                                min_edge = {j , id[*it] , w};
                            }
                            auto it2 = it;
                            ++it2;
                            if(it2 != all_vertices.end()){
                                int w = abs(D - abs(a[j] - *it2));
                                if(w < min_edge[2]){
                                    min_edge = {j , id[*it2] , w};
                                }
                            }
                        }
                        if(it != all_vertices.begin()){
                            --it;        
                            int w = abs(D - abs(a[j] - *it));
                            if(w < min_edge[2]){
                                min_edge = {j , id[*it] , w};
                            }
                        }
                    }
                }
            }
            for(int j : component[i]){
                all_vertices.insert(a[j]);
            }
            if(min_edge[0] != -1){
                edges_this_round.push_back(min_edge);
            }
        }
        for(auto& e : edges_this_round){
            int u = e[0] , v = e[1] , w = e[2];
            if(find(u) != find(v)){
                --ncomponent;
                merge(u , v);
                MST[u].emplace_back(v , w);
                MST[v].emplace_back(u , w);
            }
        }
    }
    DFS(start , -1 , 0);
    while(Q--){
        int i , k;
        cin >> i >> k;
        if(minK[i] <= k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}   
// frog can jump from a[i] to a[j] if k >= |d - |a[i] - a[j]||
// key : Borůvka's algorithm https://en.wikipedia.org/wiki/Bor%C5%AFvka's_algorithm (runs in E * logV normally)
// Kruskal (runs in E * logE , which is V^2 * logV^2 , too slow)
// given a component, how do we find the edge with smallest weight linked to a different component efficiently?
// answer: for each vertex i in this component we find some vertex j (in other components), such that |D - |a[i] - a[j]|| is smallest
// , by querying the cloest a[j] to a[i] - D , a[i] + D , -a[i] - D , -a[i] + D so as to minimise |D - |a[i] - a[j]|| , 
// which means we only need to consider at most 12 edges per vertex in a component
// log(2e5) * 12 * 2e5 * log(2e5) ~ 777600000 which will fit in 5s.