#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int mod = 1e9 + 9;
char ss[11];
int n, m, tot, ans;
int mean[maxn], f[maxn][maxn][11];
int c[maxn][5], fail[maxn], cnt[maxn];
inline void insert() {
    int p = 0;
    int len = strlen(ss);
    for (int i = 0; i < len; ++ i) {
        int idx = mean[(int)ss[i]];
        if (!c[p][idx]) c[p][idx] = ++ tot;
        p = c[p][idx];
    }
    cnt[p] = len;
}
queue<int> q;
inline void bfs() {
    for (int i = 0; i < 4; ++ i)
        if (c[0][i]) q.push(c[0][i]);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 4; ++ i) {
            int v = c[u][i];
            if (!v) {c[u][i] = c[fail[u]][i]; continue;}
            fail[v] = c[fail[u]][i];
            cnt[v] = max(cnt[v], cnt[fail[v]]);
            q.push(v);
        }
    }
    for(int i = 0; i <= tot; ++i){
        printf("val[%d] = %d\n" , i , cnt[i]);
        printf("fail[%d] = %d\n" , i , fail[i]);
    }
}
inline void add(int &a, int b) {
    a += b;
    a = (a >= mod) ? a - mod : a;
}
inline void dp() {
    f[0][0][0] = 1;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j <= tot; ++ j)
            for (int k = 0; k < 10; ++ k)
                if (f[i][j][k]) 
                    for (int p = 0; p < 4; ++ p) {
                        int son = c[j][p];
                        if (cnt[son] >= k + 1) add(f[i + 1][son][0], f[i][j][k]);
                        else add(f[i + 1][son][k + 1], f[i][j][k]);
                    }
    for (int i = 0; i <= tot; ++ i)
        add(ans, f[n][i][0]);
}
int main() {
    mean['A'] = 0, mean['G'] = 1, mean['C'] = 2, mean['T'] = 3;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%s", ss);
        insert();
    }
    bfs(), dp();
    printf("%d\n", ans); 
    return 0;
}