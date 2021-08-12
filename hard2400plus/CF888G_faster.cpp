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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int nex[maxn * 50][2] , tot , N , root;
int query(int now , int val , int bit){
    int ans = 0;
    for(; bit >= 0; --bit){
        int v = val >> bit & 1;
        if(nex[now][v]){
            now = nex[now][v];
        }
        else{
            now = nex[now][v ^ 1];
            ans |= (1 << bit);
        }
    }
    return ans;
}
void add(int& now , int val , int bit){
    if(now == 0){
        now = ++tot;
        nex[now][0] = nex[now][1] = 0;
    }
    if(bit < 0)return;
    int v = val >> bit & 1;
    add(nex[now][v] , val , bit - 1);
}
ll solve(vector<int>& a , int bit){
    if(bit < 0 || a.empty())return 0;
    vector<int> na[2];
    for(int i : a){ 
        na[i >> bit & 1].push_back(i);
    }
    ll ans = solve(na[0] , bit - 1) + solve(na[1] , bit - 1);
    if(!na[0].empty() && !na[1].empty()){
        root = tot = 0;
        for(int i : na[0]){
            add(root , i , bit - 1);
        }
        ll ret = inf64;
        for(int j : na[1]){
            ret = min(ret , (ll)query(root , j , bit - 1));
        }
        ans += ret + (1 << bit);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    tot = 1;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i)cin >> a[i];
    cout << solve(a , 29) << endl;
}       