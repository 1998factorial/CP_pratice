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
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , M , cnt[maxv] , L , R , a[maxn] , block_size;
ll ans = 0;
ll ret[maxn];
vector<array<int , 3>> querys;
void add(int i){
    if(1 <= i && i <= N){
        int v = a[i];
        ans -= (ll)cnt[v] * cnt[v] * v;
        ++cnt[v];
        ans += (ll)cnt[v] * cnt[v] * v;
    }
}
void del(int i){
    if(1 <= i && i <= N){
        int v = a[i];
        ans -= (ll)cnt[v] * cnt[v] * v;
        --cnt[v];
        ans += (ll)cnt[v] * cnt[v] * v;
    }
}
void query(int l , int r){
    while(L < l){
        del(L);
        ++L;
    }
    while(L > l){
        --L;
        add(L);
    }
    while(R < r){
        ++R;
        add(R);
    }
    while(R > r){
        del(R);
        --R;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    block_size = sqrt(N);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= M; ++i){
        int l , r;
        cin >> l >> r;
        querys.push_back({l , r , i});
    }
    L = 1 , R = N;
    for(int i = 1; i <= N; ++i)add(i);
    sort(querys.begin() , querys.end() , [&](array<int , 3>& l , array<int , 3>& r){
        int b1 = l[0] / block_size , b2 = r[0] / block_size;
        if(b1 == b2)return l[1] < r[1];
        return b1 < b2;
        // return (b1 ^ b2) ? b1 < b2 : ((b1 & 1) ? l[1] < r[1] : l[1] > r[1]);
        // faster? 
    });
    for(auto& qs : querys){
        int l = qs[0] , r = qs[1] , id = qs[2];
        query(l , r);
        ret[id] = ans;
    }
    for(int i = 1; i <= M; ++i){
        cout << ret[i] << endl;
    }
}   

// MO 