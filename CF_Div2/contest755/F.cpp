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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int mp[256] , len[15] , N , a[15][105] , dp[55][2000] , pos[15][55][2];
pii nex[55][2000];
char s[15][105] , imp[55];
// pos[i][j][0] = first position of j in s[i]
// pos[i][j][1] = second position of j in s[i] 
int solve(int c , int mask){
    int& ret = dp[c][mask];
    if(~ret)return ret;
    ret = 1;
    for(int nc = 0; nc <= 52; ++nc){
        int ok = 1 , nmask = 0;
        for(int i = 0; i < N; ++i){
            int v = mask >> i & 1;
            int cur_pos = pos[i][c][v];
            if(pos[i][nc][0] > cur_pos){
                nmask |= 0;
            }
            else if(pos[i][nc][1] > cur_pos){
                nmask |= (1 << i);
            }
            else{
                ok = 0;
                break;
            }
        }
        if(ok){
            int ret_val = solve(nc , nmask) + 1;
            if(ret < ret_val){
                nex[c][mask] = {nc , nmask};
                ret =  ret_val;
            }
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(char x = 'a'; x <= 'z'; ++x){
        mp[x] = (int)(x - 'a' + 1);
        imp[mp[x]] = x;
    }
    for(char x = 'A'; x <= 'Z'; ++x){
        mp[x] = (int)(x - 'A' + 26 + 1);
        imp[mp[x]] = x;
    }
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        memset(dp , -1 , sizeof(dp));
        memset(pos , -1 , sizeof(pos));
        for(int i = 0; i <= 52; ++i){
            for(int mask = 0; mask < 1 << N; ++mask){
                nex[i][mask] = {-1 , -1};
            }
        }
        for(int i = 0; i < N; ++i){
            cin >> (s[i] + 1);
            len[i] = strlen(s[i] + 1);
            for(int j = 1; j <= len[i]; ++j){
                a[i][j] = mp[s[i][j]];
            }
            for(int j = 1; j <= len[i]; ++j){
                if(pos[i][a[i][j]][0] == -1){
                    pos[i][a[i][j]][0] = j;
                }
                else if(pos[i][a[i][j]][1] == -1){
                    pos[i][a[i][j]][1] = j;
                }
            }
            pos[i][0][0] = pos[i][0][1] = 0;
        }
        cout << solve(0 , 0) - 1 << endl;
        vector<char> lcs;
        int c = 0 , mask = 0;
        while(~c && ~mask){
            int nc = nex[c][mask].x , nmask = nex[c][mask].y;
            if(c > 0){
                lcs.push_back(imp[c]);
            }
            c = nc;
            mask = nmask;
        }
        for(char x : lcs)cout << x;
        cout << endl;
    }
}

// N <= 10
// freq[i] <= 2 , i in [a,z] U [A,Z]
// |s[i]| <= 104
// if we have 2 sequences, LCS can be found in O(N^2)
// generalise to k sequences, O(N^k) , by keeping track with positions
// in each sequences
// since freq[i] <= 2, we just need to keep track with if we are on 
// first of it or second of it. so we can optimize the state to 
// dp[c][mask] , c stands for the current character, in mas
// bit[i] = 0 -> we are on ith string's first position of c
// bit[i] = 1 -> we are on ith string's second position of c