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
const int maxn = 1e6 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , cnt[10] , nprimes = 0;
ll a[10];
int solve(int pos , vector<ll>& tree , int nchild , int nroot){
    if(pos >= N){
        return nchild + (nroot > 1) + N - nprimes;
    }
    int ans = inf32;
    for(int i = 0; i < tree.size(); ++i){
        if(tree[i] % a[pos] == 0){
            tree[i] /= a[pos];
            tree.push_back(a[pos]);
            int nnchild = (i == 0) ? nchild + cnt[pos] : nchild;
            int nnroot = (i == 0) ? nroot + 1 : nroot;
            ans = min(ans , solve(pos + 1 , tree , nnchild , nnroot));
            tree[i] *= a[pos];
            tree.pop_back();
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i)cin >> a[i];
    sort(a , a + N);
    reverse(a , a + N);
    for(int i = 0; i < N; ++i){
        ll t = a[i];
        for(ll v = 2; v * v <= t; ++v){
            while(t % v == 0){
                t /= v;
                ++cnt[i];
            }
        }
        if(t > 1)++cnt[i];
        if(cnt[i] == 1){
            ++nprimes;
        }
    }
    vector<ll> tree;
    tree.push_back(0);
    cout << solve(0 , tree , 0 , 0) << endl;
}   
