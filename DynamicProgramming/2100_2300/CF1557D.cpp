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
const int maxv = 1e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N , M , cnt[maxn] , vis[maxn] , dp[maxn] , nex[maxn] , keep[maxn];
set<int> ids;
vector<pii> events; // (bound , id)
vector<int> g[maxn];
void DFS(int v){
    dp[v] = 1;
    vis[v] = 1;
    for(int nv : g[v]){
        if(!vis[nv])DFS(nv);
        if(dp[nv] + 1 > dp[v]){
            dp[v] = dp[nv] + 1;
            nex[v] = nv;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ids.insert(0);
    ids.insert(inf32);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int id , l , r;
        cin >> id >> l >> r;
        events.emplace_back(l , id);
        events.emplace_back(r + 1 , -id);
    }
    sort(events.begin() , events.end());
    for(auto [v , id] : events){
        if(id < 0){
            --cnt[-id];
            if(cnt[-id] <= 0){
                ids.erase(-id);
            }
        }
        else{
            ++cnt[id];
            if(cnt[id] == 1){
                ids.insert(id);
            }
            auto it = ids.upper_bound(id);
            if(*it <= N && *it >= 1){
                g[id].push_back(*it);
            }
            it = ids.find(id);
            --it;
            if(*it <= N && *it >= 1){
                g[*it].push_back(id);
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        g[0].push_back(i);
    }
    memset(nex , -1 , sizeof(nex));
    DFS(0);
    int cur = 0;
    while(~cur){
        keep[cur] = 1;
        cur = nex[cur];
    }
    int cnt = 0;
    for(int i = 1; i <= N; ++i)if(!keep[i])++cnt;
    cout << cnt << endl;
    for(int i = 1; i <= N; ++i)if(!keep[i])cout << i << ' ';
    cout << endl;
} 