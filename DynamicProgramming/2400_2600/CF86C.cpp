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
const int maxn = 1005;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const int mod = 1e9 + 9;
int add(int x , int y){
    ll ans = x;
    ans += y;
    if(ans >= mod)ans -= mod;
    return ans;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
int id(char s){
    if(s == 'A')return 0;
    if(s == 'C')return 1;
    if(s == 'G')return 2;
    return 3;
}
int N , M;
int tr[maxn][5] , tot , val[maxn] , fail[maxn];
int dp[maxn][maxn][15];
void add_trie(string s){
    int now = 0 , sz = s.size();
    for(int i = 0; i < sz; ++i){
        int v = id(s[i]);
        if(!tr[now][v]){
            tr[now][v] = ++tot;
        }
        now = tr[now][v];
    }
    val[now] = max(val[now] , sz);
}
void build_AC_automaton(){
    queue<int> q;
    for(int i = 0; i < 4; ++i){
        if(tr[0][i]){
            q.push(tr[0][i]);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            if(tr[u][i]){
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
                val[tr[u][i]] = max(val[tr[u][i]] , val[fail[tr[u][i]]]);
            }
            else{
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
    for(int i = 0; i <= tot; ++i){
        printf("val[%d] = %d\n" , i , val[i]);
        printf("fail[%d] = %d\n" , i , fail[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    tot = 0;
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        string dna;
        cin >> dna;
        add_trie(dna);
    }
    build_AC_automaton();
    dp[0][0][0] = 1;
    // dp[i][j][k] = number of prefix of length i (consists of 4 different DNA letters)
    // such that we are up the jth node on the AC automaton and the length of the unmatched
    // suffix = k
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= tot; ++j){
            for(int k = 0; k < 10; ++k){
                if(dp[i][j][k] == 0)continue;
                for(int x = 0; x < 4; ++x){
                    int nj = tr[j][x];
                    if(val[nj] >= 1 + k){
                        dp[i + 1][nj][0] = add(dp[i + 1][nj][0] , dp[i][j][k]);
                    }
                    else{
                        dp[i + 1][nj][k + 1] = add(dp[i + 1][nj][k + 1] , dp[i][j][k]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= tot; ++i){
        ans = add(ans , dp[N][i][0]);
    }
    cout << ans << endl;
}   