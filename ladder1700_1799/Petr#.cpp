#include <bits/stdc++.h>
#define MAX_SIZE 2005
using namespace std;
typedef long long ll;

struct rolling_hash {
    ll val[MAX_SIZE];
    ll ep[MAX_SIZE];
    ll mod = 1e9 + 9;
    int base = 1331;
    int N;
    void init(int base=1331, ll mod=1e9 + 9) {
        int i;
        this->base = base, this->mod = mod;
        ep[0] = 1;
        for (i = 1; i < MAX_SIZE; ++i) {
            ep[i] = ep[i-1] * base;
            //ep[i] %= mod; 
        }
    }

    void calc(char st[], int N) {
        this->N = N;
        for (int i = 1 ; i <= N; ++i) {
            val[i] = val[i-1] * base + (st[i] - 'a' + 1);
            //val[i] %= mod;
        }
    }

    ll decode(int l, int r) {
        ll valL = val[l - 1] * ep[r - l + 1];
        ll valR = val[r];
        return valR - valL;
        //return ((valR - valL) % mod + mod) % mod;
    }

    bool equal(int l1, int r1, int l2, int r2) {
        if (r1 - l1 != r2 - l2) return false;
        return decode(l1, r1) == decode(l2, r2);
    }
};

struct rolling_hash H;

char a[2005] , b[2005] , c[2005];
int N1 , N2 , N3 , L[2005] , R[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> (a + 1);
    cin >> (b + 1);
    cin >> (c + 1);
    N1 = strlen(a + 1);
    N2 = strlen(b + 1);
    N3 = strlen(c + 1);
    for(int i = 1; i <= N1; ++i){
        if(i + N2 - 1 <= N1){
            int ok = 1;
            for(int j = 1; j <= N2 && ok; ++j){
                if(a[i + j - 1] != b[j]){
                    ok = 0;
                }
            }
            L[i] = ok;
        }
    }
    for(int i = N1; i >= 1; --i){
        if(i - N3 + 1 >= 1){
            int ok = 1;
            for(int j = 1; j <= N3 && ok; ++j){
                if(a[i - j + 1] != c[N3 - j + 1]){
                    ok = 0;
                }
            }
            R[i] = ok;
        }
    }
    H.init();
    H.calc(a , N1);
    unordered_set<ll> ans;
    for(int i = 1; i <= N1; ++i){
        for(int j = i; j <= N1; ++j){
            if(L[i] && R[j] && j - i + 1 >= max(N2 , N3)){
                ans.insert(H.decode(i , j));
            }
        }
    }
    cout << ans.size() << endl;
}