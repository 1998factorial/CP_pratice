#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int from, to, capacity, cost;
};
 
vector<vector<int>> adj, cost, capacity;
vector<Edge> edges;
int d,n;
int passwords[2000];
int passwordCounts[2000];
char tem[11];
bool has_child[2000];
bool has_parent[2000];
 
const int INF = 1e9;
bool seen[2000];
char ouf[100000];
 
void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
 
int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
 
    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
 
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    // cout << flow << endl;
    if (flow < K)
        return -1;
    else
        return cost;
}
int main() {
    scanf("%d %d",&d,&n);
    int s = 2*n;
    int t = 2*n+1;
    Edge temE;
    for (int i=0;i<n;i++) {
        scanf("%s",tem);
        for (int j=0;j<d;j++) {
            passwords[i] <<= 1;
            passwords[i] += tem[j]-'0';
            if (tem[j]-'0') {
                passwordCounts[i]++;
            }
        }
        // cout << passwords[i] << endl;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            // cout << i << " " << j << " " << (passwords[i] & passwords[j]) << endl;
            if (i != j && (passwords[i] & passwords[j]) == passwords[i]) {
                // cout << i << " " << j << " " << (passwords[i] & passwords[j]) << " " << passwordCounts[i] << endl;
                temE.from = i;
                temE.to = j+n;
                temE.capacity = 1;
                // temE.cost = 1;
                temE.cost = -passwordCounts[i];
                edges.push_back(temE);
                has_child[j] = true;
                has_parent[i] = true;
            }
        }
    }
    int no_childs = 0;
    int out = 0;
    int curC = 0;
    for (int i=0;i<n;i++) {
        temE.from = s;
        temE.to = i;
        temE.capacity = 1;
        temE.cost = 0;
        edges.push_back(temE);
        temE.from = i;
        temE.to = t;
        temE.capacity = 1;
        temE.cost = 0;
        edges.push_back(temE);
        temE.from = i+n;
        temE.to = t;
        temE.capacity = 1;
        temE.cost = 0;
        edges.push_back(temE);
    }
    cout << "mincost = " << min_cost_flow(2*n+2,edges,n,s,t) << endl;

    int used = 0;
    for (int i=0;i<n;i++) {
        if (seen[i]) {continue;}
        bool checkB = false;
        for (int j=0;j<n;j++) {
            if ((i != j) && cost[j][i+n] < 0 && capacity[j][i+n] == 0) {
                checkB = true;
                break;
            }
        }
        if (checkB) {continue;}
        used++;
        seen[i] = true;
        int cur = i;
        int temI = 1;
        // cout << i << " " << passwords[i] << endl;
        for (int j=0;j<d;j++) {
            if (passwords[i]&temI) {
                ouf[curC] = '0'+d-j-1;
                ouf[curC+1] = ' ';
                curC+=2;
                out++;
            }
            temI <<= 1;
        }
        while (true) {
            int next = cur;
            for (int j=0;j<n;j++) {
                if (cost[cur][j+n] < 0 && capacity[cur][j+n] == 0) {
                    next = j;
                    break;
                }
            }
            if (next == cur) {break;}
            seen[next] = true;
            // cout << next << " " << cur << endl;
            int diff = (passwords[next] ^ passwords[cur]);
            temI = 1;
            used++;
            for (int j=0;j<d;j++) {
                if (diff&temI) {
                    ouf[curC] = '0'+d-j-1;
                    ouf[curC+1] = ' ';
                    curC+=2;
                    out++;
                }
                temI <<= 1;
            }
            cur = next;
        }
        if (used < n) {
            ouf[curC] = 'R';
            ouf[curC+1] = ' ';
            curC+=2;
            out++;
        }
    }
    ouf[curC-1]='\0';
    printf("%d\n",out);
    printf("%s\n",ouf);
}