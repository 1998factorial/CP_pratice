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
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N , Q , a[maxn] , b[maxn]; 
ll prefix[maxn];
ll table[25][maxn];
ll table_max[25][maxn];
int logs[maxn];
ll query(int l , int r) {
    if(l > r)return 0;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return min(table[logs[len]][l] , table[logs[len]][pos]);
}
ll query_max(int l , int r){
    if(l > r)return 0;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return max(table_max[logs[len]][l] , table_max[logs[len]][pos]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= N; ++i)cin >> b[i];
    for(int i = 1; i <= N; ++i){
        prefix[i] = prefix[i - 1] + a[i] - b[i];
    }
    for(int i = 2; i < maxn; ++i){
        logs[i] = logs[i / 2] + 1;
    }
    for(int i = 1; i <= N; ++i){
        table[0][i] = table_max[0][i] = prefix[i];
    }
    for(int i = 1; i <= logs[N]; ++i){
        int prel = (1 << (i - 1));
        for(int j = 1; j <= N; ++j){
            if(j + prel <= N){
                table_max[i][j] = max(table_max[i - 1][j] , table_max[i - 1][j + prel]);
                table[i][j] = min(table[i - 1][j] , table[i - 1][j + prel]);
            }
            else{
                table_max[i][j] = table_max[i - 1][j];
                table[i][j] = table[i - 1][j];
            }
        }
    }
    while(Q--){
        int l , r;
        cin >> l >> r;
        if(prefix[r] - prefix[l - 1] != 0 || query_max(l , r) - prefix[l - 1] > 0){
            cout << -1 << endl;
        }
        else{
            cout << -query(l , r) + prefix[l - 1] << endl;
        }
    }
} 