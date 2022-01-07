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
const int maxn = 4e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , M , a[505][505] , b[505][505];
namespace Flow {
    #define x first
    #define y second
    typedef long long ll;
    typedef pair<int , int> pii;

    const int maxn = 5000;
    const double INF = 1e12;
    const double ep = 1e-8;

    struct Edge {
        int from, to;
        double cap, flow;
        Edge(int u, int v, double c, double f) : from(u), to(v), cap(c), flow(f) {}
        };

    struct Dinic {
        int n, m, s, t;
        vector<Edge> edges;
        vector<int> G[maxn];
        int d[maxn], cur[maxn];
        bool vis[maxn];

        void init() {
            for (int i = 0; i < maxn; i++) G[i].clear();
            edges.clear();
        }

        void add(int from, int to, double cap) {
            edges.push_back(Edge(from, to, cap, 0));
            edges.push_back(Edge(to, from, 0 , 0));
            m = edges.size();
            G[from].push_back(m - 2);
            G[to].push_back(m - 1);
        }

        bool BFS() {
            memset(vis, 0, sizeof(vis));
            queue<int> Q;
            Q.push(s);
            d[s] = 0;
            vis[s] = 1;
            while (!Q.empty()) {
                int x = Q.front();
                Q.pop();
                for (int i = 0; i < G[x].size(); i++) {
                    Edge& e = edges[G[x][i]];
                    if (!vis[e.to] && e.cap - e.flow > ep) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                    }
                }
            }
            return vis[t];
        }

        double DFS(int x, double a) {
            if (x == t || a == 0) return a;
            double flow = 0, f;
            for (int& i = cur[x]; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                    e.flow += f;
                    edges[G[x][i] ^ 1].flow -= f;
                    flow += f;
                    a -= f;
                    if (a == 0) break;
                }
            }
            return flow;
        }

        double maxFlow(int s, int t) {
            this->s = s;
            this->t = t;
            double flow = 0;
            while (BFS()) {
                memset(cur, 0, sizeof(cur));
                flow += DFS(s, INF);
            }
            return flow;
        }

        void show(){
            for(const auto& e : edges){
                printf("(%d -> %d) => cap = %f , flow = %f\n" , e.from , e.to , e.cap , e.flow);
            }
        }

        void DFS2(int v){
            vis[v] = true;
            for(int i = 0; i < G[v].size(); ++i){
                Edge e = edges[G[v][i]];
                if(!vis[e.to] && e.cap - e.flow > ep){
                    DFS2(e.to);
                }
            }
        }

        vector<pii> extract(){
            vector<pii> ans;
            for(const auto& e : edges){
                if(e.cap > 0 && e.cap == e.flow){
                    ans.push_back({e.from , e.to});
                }
            }
            return ans;
        }

    };
    Dinic G;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            char s;
            cin >> s;
            if(s == 'B')a[i][j] = 1;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(a[i][j]){
                b[i][j] ^= 1;
                b[i - 1][j] ^= 1;
                b[i][j - 1] ^= 1;
                b[i - 1][j - 1] ^= 1;
            }
        }
    }
    Flow::G.init();
    int s = N + M + 10 , t = N + M + 11;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            set<pii> v;
            v.insert({i , j});
            v.insert({i , M});
            v.insert({N , j});
            v.insert({N , M});
            if(v.size() < 4)continue;
            if(b[i][j] && b[i][M] && b[N][j]){
                Flow::G.add(i , j + N , 1);
                //cout << i << " to " << j << endl;
            }
        }
    }
    for(int i = 1; i <= N; ++i)Flow::G.add(s , i , 1);
    for(int i = 1; i <= M; ++i)Flow::G.add(i + N , t , 1);
    int up = Flow::G.maxFlow(s , t);
    vector<pii> vec = Flow::G.extract();
    vector<pii> op2;
    for(const auto& e : vec){
        if(e.x != s && e.y != t){
            op2.push_back(e);
        }
    }
    int ones = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(b[i][j])++ones;
        }
    }
    int ans = ones;
    for(int i = 0; i < op2.size(); ++i){
        int r = op2[i].x , c = op2[i].y - N;
        ones += (b[r][c]) ? -1 : 1;
        ones += (b[r][M]) ? -1 : 1;
        ones += (b[N][c]) ? -1 : 1;
        ones += (b[N][M]) ? -1 : 1;
        b[r][c] ^= 1;
        b[r][M] ^= 1;
        b[N][c] ^= 1;
        b[N][M] ^= 1;
        ans = min(ans , ones + 2 * (i + 1));
    }
    cout << ans << endl;
} 