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
int N;
ll a[maxn];
int fa[maxn] , b[maxn] , nex[maxn * 30][2] , tot , num[maxn * 30 * 2] , limit;
vector<int> component[maxn];
set<int> here[maxn];
vector<int> tmp;
vector<int> id;
unordered_map<int , int> mp;
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y){
    x = find(x);
    y = find(y);
    if(x != y){
        if(component[x].size() < component[y].size())swap(x , y);
        for(int i : component[y]){
            fa[i] = x;
            component[x].push_back(i);
        }
        component[y].clear();
    }
}
void init(int N){
    for(int i = 1; i <= N; ++i){
        fa[i] = i;
        component[i].push_back(i);
    }
}
void add(int val , int d , int index){
    int now = 1;
    for(int i = limit; i >= 0; --i){
        int v = val >> i & 1;
        if(!nex[now][v]){
            nex[now][v] = ++tot;
        }
        now = nex[now][v];
        num[now] += d;
    }
    if(d == 1){
        here[id[index]].insert(index);
    }
    else if(d == -1){
        here[id[index]].erase(index);
    }
}
int query(int val){
    int now = 1 , ans = 0;
    for(int i = limit; i >= 0; --i){
        int v = val >> i & 1;
        if(nex[now][v] && num[nex[now][v]] > 0){
            now = nex[now][v];
            ans |= (1 << i) * v;
        }
        else{
            now = nex[now][v ^ 1];
            ans |= (1 << i) * (1 - v);
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < maxn; ++i)here[i].clear();
    tot = 1;
    tmp.clear();
    cin >> N;
    init(N);
    limit = 0;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        tmp.push_back(a[i]);
        for(int j = 29; j >= 0; --j){
            if(a[i] >> j & 1){
                limit = max(limit , j);
                break;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        mp[a[i]] = i;
    }
    sort(tmp.begin() , tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    id = vector<int>(N + 1);
    for(int i = 1; i <= N; ++i){
        id[i] = lower_bound(tmp.begin() , tmp.end() , a[i]) - tmp.begin();
    }
    for(int i = 1; i <= N; ++i){
        add(a[i] , 1 , i);
    }
    int ncomponent = N;
    ll ans = 0;
    while(ncomponent > 1){
        vector<array<int , 3>> added_edges;
        vector<bool> vis(N + 1);
        for(int i = 1; i <= N; ++i){
            if(component[i].empty())continue;
            if(vis[find(i)])continue;
            for(int j : component[i]){
                add(a[j] , -1 , j);
            }
            array<int , 3> new_edge = {-1 , -1 , inf32};
            for(int j : component[i]){
                int ret = query(a[j]);
                if(mp[ret] == 0)continue;
                int t = id[mp[ret]];
                //int t = lower_bound(tmp.begin() , tmp.end() , ret) - tmp.begin();
                if(here[t].empty())continue;
                int k = *here[t].begin();
                int w = ret ^ a[j];
                if(w < new_edge[2]){
                    new_edge = {j , k , w};
                }
            }
            for(int j : component[i]){
                add(a[j] , 1 , j);
            }
            if(~new_edge[0]){
                added_edges.push_back(new_edge);
                vis[find(new_edge[0])] = vis[find(new_edge[1])] = 1;
            }
        }
        for(auto& e : added_edges){
            int v = e[0] , u = e[1] , w = e[2];
            if(find(v) == find(u))continue;
            --ncomponent;
            merge(u , v);
            ans += w;
        }
    }
    cout << ans << endl;
}       
/*
For normal MST problem we use Kruskal O(E * logE)
In our case, this will be O(N^2 * logN^2) too slow
So we should try Borůvka's algorithm
We can make make this run in O(logV * E) or faster
Can we speed up each logV iteration? 
Instead of iterating all edges, for each vertices v, we query the 
vertex u in another component which will result in the minimal xor 
value min{v xor u} by maintaining a trie
So , the total time complexity is O(logV * V * 30) since a[i] < 2^30

Sadly , the constant factor is too big, and I don't know how make it AC 
:(
*/