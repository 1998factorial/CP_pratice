// with this as root, what is the black node with the highest number of child black nodes

#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

int n;
int c[MAXN];
int b[MAXN]; // number of black nodes under this
int bb; // number of black nodes with black nodes under
vector<int> nx[MAXN];
int x, y;
int a[MAXN];
int nxc[MAXN];

int cc; // has two or more black below and is exactly next to a black

int is_bb(int at) {
    return c[at] && b[at] >= 2;
}

int is_cc(int at) {
    if (b[at] >= 2) {
        return nxc[at];
    }
    return false;
}

void print_debug() {
    for (int i = 1; i <= n; i++) {
        printf("(c[%d],b[%d],a[%d],bb) = (%d,%d,%d,%d)\n", i, i, i, c[i], b[i], a[i], bb);
    }
}

void dfs(int at, int prev) {
    for (int next : nx[at]) {
        if (next != prev) {
            dfs(next, at);
            b[at] += b[next];
        }
    }
    b[at] += c[at];
    bb += is_bb(at);
    cc += is_cc(at);
}

int answer = 0;

// change root from a to b
void reroot(int from, int to) {
    bb -= is_bb(from);
    bb -= is_bb(to);
    cc -= is_cc(from);
    cc -= is_cc(to);

    int from_bak = b[from];
    int to_bak = b[to];
    b[to] = from_bak;
    b[from] = from_bak - to_bak;

    bb += is_bb(from);
    bb += is_bb(to);
    cc += is_cc(from);
    cc += is_cc(to);
}

void rdfs(int at, int prev) {
    if (bb) a[at] = 1;
    if (cc) a[at] = 1;
    if (c[at]) a[at] = 1;
    for (int next : nx[at]) {
        if (c[next]) {
            a[at] = 1;
        }
        if (next != prev) {
            reroot(at, next);
            rdfs(next, at);
            reroot(next, at);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 2; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        nx[x].push_back(y);
        nx[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        for (int next : nx[i]) {
            if (c[next]) {
                nxc[i] = true;
                break;
            }
        }
    }

    dfs(1, 0);
    rdfs(1, 0);

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}