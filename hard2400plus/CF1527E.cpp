#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 35005;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , K , a[maxn] , L , R , cost , dp[maxn][105];
deque<int> pos[maxn];

void query(int l , int r){ // invariant l <= r
    while(L < l){ //pop out
        int p = L;
        pos[a[L]].pop_front();
        int np = pos[a[L]].empty() ? p : pos[a[L]].front();
        cost -= np - p;
        ++L;
    }
    while(L > l){ //push in
        --L;
        int p = L;
        int np = pos[a[L]].empty() ? L : pos[a[L]].front();
        cost += np - p;
        pos[a[L]].push_front(L);
    }
    while(R < r){ //push in
        ++R;
        int np = R , p = pos[a[R]].empty() ? R : pos[a[R]].back();
        cost += np - p;
        pos[a[R]].push_back(R);
    }
    while(R > r){ //pop out
        int np = R;
        pos[a[R]].pop_back();
        int p = pos[a[R]].empty() ? np : pos[a[R]].back();
        cost -= np - p;
        --R;
    }
}

void solve(int l , int r , int x , int y , int k){
    if(l > r)return;
    int mid = (l + r) >> 1;
    int pos = -1;
    dp[mid][k] = inf32;
    for(int i = x; i <= min(y , mid); ++i){
        query(i , mid);
        if(cost + dp[i - 1][k - 1] < dp[mid][k]){
            dp[mid][k] = cost + dp[i - 1][k - 1];
            pos = i;
        }
    }
    solve(l , mid - 1 , x , pos , k);
    solve(mid + 1 , r , pos , y , k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    cost = 0;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        if(!pos[a[i]].empty())cost += i - pos[a[i]].back();
        pos[a[i]].push_back(i);
        dp[i][1] = cost;
    }
    L = 1 , R = N;
    for(int k = 2; k <= K; ++k){
        solve(1 , N , 1 , N , k);
    }
    cout << dp[N][K] << endl;
}