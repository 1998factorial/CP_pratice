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
const ll mod = 1e9 + 7;
int sum[maxn << 2];
void update(int pos , int N , int val){
    while(pos <= N){
        sum[pos] += val;
        pos += pos & (-pos);
    }
}
int ask(int pos){
    int ans = 0;
    while(pos){
        ans += sum[pos];
        pos -= pos & (-pos);
    }
    return ans;
}
int query(int l , int r){
    return ask(r) - ask(l - 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> b(N + 1);
        vector<int> tmp;
        for(int i = 1; i <= N; ++i)cin >> b[i] , tmp.push_back(b[i]);
        sort(tmp.begin() , tmp.end());
        map<int , int> id;
        int sz = 0;
        for(int i : tmp){
            if(id[i] == 0){
                id[i] = ++sz;
            }
        }
        for(int i = 0; i <= (sz + 1) * 4; ++i)sum[i] = 0;
        vector<bool> vis(sz + 1);
        int ok = 1;
        for(int i = 1; i <= N; ++i){
            int x = id[b[i]];
            if(!vis[x]){
                vis[x] = 1;
                update(x , sz + 1 , 1);
            }
            if(i > 1){
                int l = min(id[b[i - 1]] , x);
                int r = max(id[b[i - 1]] , x);
                if(abs(query(l , r)) > 2){
                    ok = 0;
                }
            }
        }
        if(ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}