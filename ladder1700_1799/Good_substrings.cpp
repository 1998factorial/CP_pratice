#include <bits/stdc++.h>
#define MAX_SIZE 1505
using namespace std;
typedef long long ll;
char a[1505] , good[26];
int N , K , sum[1505];

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> (a + 1);
    cin >> good; 
    cin >> K;
    N = strlen(a + 1);
    for(int i = 1; i <= N; ++i){
        sum[i] += sum[i - 1];
        if(good[a[i] - 'a'] == '0')++sum[i];
    }
    H.init();
    H.calc(a , N);
    set<ll> ans;
    for(int i = 1; i <= N; ++i){
        //string tmp = "";
        for(int j = i; j <= N; ++j){
            //tmp += a[j];
            if(sum[j] - sum[i - 1] <= K){
                //ans.insert(tmp);
                ans.insert(H.decode(i , j));
            }
            else{
                break;
            }
        }
    }
    cout << ans.size() << endl;
}