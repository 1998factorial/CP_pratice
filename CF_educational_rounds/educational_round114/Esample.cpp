#include <bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define ON 1
#define OFF -1
#define DEBUG(x) std::cout << #x << '=' << x << std::endl
using namespace std;
const int mod = 998244353;
 
struct pair_hash {
    template<class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 * 1000000 + h2;
    }
};
 
LL qp(LL a, int b) {
    LL ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
 
int n, m, Q;
int row[2][1000008], col[2][1000008];  //row0 = row01   导致该row不能010101的元素个数   row1 = row10  导致该row不能101010的元素个数
int existrow = 0, existcol = 0;
LL pow2[1000008];
int all[2];
unordered_map<pii, int, pair_hash> mp;
unordered_set<int> errrow, errcol;
void fuckon(pii p, int val) {
    int x = p.first, y = p.second;
 
    row[(y & 1) ^ val][x]++;
    col[(x & 1) ^ val][y]++;
 
    existrow += (row[0][x] + row[1][x] == 1);
    existcol += (col[0][y] + col[1][y] == 1);
    if (row[0][x] && row[1][x]) {
        errrow.insert(x);
    }
    if (col[0][y] && col[1][y]) {
        errcol.insert(y);
    }
    if (val == 0) {
        all[(x & 1) == (y & 1)]++;
    } else {
        all[(x & 1) != (y & 1)]++;
    }
}
 
void fuckoff(pii p, int val) {
    int x = p.first, y = p.second;
 
    row[(y & 1) ^ val][x]--;
    col[(x & 1) ^ val][y]--;
 
    existrow -= (row[0][x] + row[1][x] == 0);
    existcol -= (col[0][y] + col[1][y] == 0);
    if (!(row[0][x] && row[1][x])) {
        errrow.erase(x);
    }
    if (!(col[0][y] && col[1][y])) {
        errcol.erase(y);
    }
    if (val == 0) {
        all[(x & 1) == (y & 1)]--;
    } else {
        all[(x & 1) != (y & 1)]--;
    }
}
 
int main() {
    cin >> n >> m >> Q;
    pow2[0] = 1;
    for (int i = 1; i <= max(n, m); ++i) {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
    while (Q--) {
        LL ans = 0;
        int x, y, op;
        scanf("%d%d%d", &x, &y, &op);
        pii p = make_pair(x, y);
        if (op == -1) {
            if (mp.find(p) == mp.end()) {
                ;
            } else {
                fuckoff(p, mp[p]);
            }
            mp.erase(p);
        } else {
            if (mp.find(p) == mp.end()) {
                fuckon(p, op);
            } else {
                fuckoff(p, mp[p]);
                fuckon(p, op);
            }
            mp[p] = op;
        }
        //DEBUG(n-existrow);
        //DEBUG(m-existcol);
        ans = ( (errrow.size() == 0) * pow2[n - existrow] + (errcol.size() == 0) * pow2[m - existcol] - (all[0] == 0) - (all[1] == 0) + mod) % mod;
        printf("%lld\n", ans);
    }
}