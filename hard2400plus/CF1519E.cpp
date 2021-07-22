#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pii;
const int maxn = 2e5 + 10;
int N , vis[maxn * 2] , used_edge[maxn * 2] , M , cnt;
vector<pii> g[maxn * 2];
map<pii , int> mp;
vector<pii> ans;

int id(ll up , ll down){
    if(mp.count(make_pair(up , down)))return mp[make_pair(up , down)];
    return 0;
}

ll gcd(ll a , ll b){
    return a == 0 ? b : gcd(b % a , a);
}

void DFS(int v , int pid , int d){
    vector<int> candidates;
    vis[v] = d;
    for(auto e : g[v]){
        int nv = e.x , id = e.y;
        if(vis[nv] == 0){
            DFS(nv , id , d + 1);
            if(used_edge[id] == 0)candidates.push_back(id);
        }   
        else if(used_edge[id] == 0 && vis[v] < vis[nv]){
            candidates.push_back(id);
        }
    }
    if(((int)candidates.size() & 1) && pid != 0 && used_edge[pid] == 0){
        candidates.push_back(pid);
    }
    while(candidates.size() > 1){
        int h = candidates.back();
        used_edge[h] = 1;
        candidates.pop_back();
        int u = candidates.back();
        used_edge[u] = 1;
        candidates.pop_back();
        ans.push_back(make_pair(u , h));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    M = 0;
    cin >> N;
    // group points by slopes
    for(int i = 1; i <= N; ++i){
        ll a , b , c , d;
        cin >> a >> b >> c >> d;
        ll up = 0 , down = 0 , dd = 0;
        // (y + 1) / x
        up = (c + d) * b;
        down = a * d;
        dd = gcd(up , down);
        up /= dd;
        down /= dd;
        if(mp.count(make_pair(up , down)) == 0)mp[make_pair(up , down)] = ++M;
        auto v = id(up , down);
        // y / (x + 1) 
        up = c * b;
        down = (a + b) * d;
        dd = gcd(up , down);
        up /= dd;
        down /= dd;
        if(mp.count(make_pair(up , down)) == 0)mp[make_pair(up , down)] = ++M;
        auto u = id(up , down);
        g[u].push_back(make_pair(v , i));
        g[v].push_back(make_pair(u , i));
    }
    for(int i = 1; i <= M; ++i){
        if(vis[i] == 0){
            DFS(i , 0 , 1);
        }
    }
    cout << (int)ans.size() << endl;
    for(auto e : ans){
        cout << e.x << " " << e.y << endl;
    }
}