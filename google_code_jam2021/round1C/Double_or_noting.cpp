#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;
const int inf = 1e8;
int complement[1 << 20];
void solve(){
    string a , b;
    cin >> a;
    cin >> b;
    int mask1 = 0 , mask2 = 0;
    for(int i = a.size() - 1; i >= 0; --i){
        mask1 = 2 * mask1 + (a[i] - '0');
    }
    for(int i = b.size() - 1; i >= 0; --i){
        mask2 = 2 * mask2 + (b[i] - '0');
    }
    queue<array<int , 2>> q;
    map<int , int> vis;
    q.push({mask1 , 0});
    int f = 0;
    while(!q.empty()){
        auto c = q.front();
        q.pop();
        if(c[0] == mask2){
            f = 1;
            cout << c[1] << endl;
            break;
        }
        if(vis[c[0]]){
            continue;
        }
        vis[c[0]] = 1;
        if(!vis[c[0] * 2]){
            q.push({c[0] * 2 , c[1] + 1});
        }
        if(!vis[complement[c[0]]]){
            q.push({complement[c[0]] , c[1] + 1});
        }
    }
    if(!f)cout << "IMPOSSIBLE" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int mask = 0; mask < 1 << 20; ++mask){
        int high = 0;
        for(int i = 0; i < 30; ++i)if((mask >> i) & 1)high = i;
        for(int i = high; i >= 0; --i){
            if((mask >> i) & 1)continue;
            complement[mask] |= (1 << i);
        }
    }
    for(int kase = 1; kase <= t; ++kase){
        cout << "Case #" << kase << ": ";
        solve();
    }
}