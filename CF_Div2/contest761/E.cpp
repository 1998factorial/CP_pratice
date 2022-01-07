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
int N , a[200005] , tot;
unordered_map<int , int> val_id , rev_id , mp;
vector<int> g[200005 * 30];
void build_up(int v){
    if(val_id[v] > 0 || v == 0)return;
    val_id[v] = ++tot;
    rev_id[tot] = v;
    int k = ceil(log2(v));
    int nv = (1ll << k) - v;
    build_up(nv);
    g[val_id[v]].push_back(val_id[nv]);
    g[val_id[nv]].push_back(val_id[v]);
}
int val , root , root2;
void DFS(int v , int p , int dep){
    for(int nv : g[v]){
        if(nv != p){
            DFS(nv , v , dep + 1);
        }
    }
    if(dep > val && mp[rev_id[v]]){
        val = dep;
        root = v;
    }
}
void DFS2(int v , int p , int dep){
    for(int nv : g[v]){
        if(nv != p){
            DFS2(nv , v , dep + 1);
        }
    }
    if(dep > val && mp[rev_id[v]]){
        val = dep;
        root2 = v;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    tot = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        mp[a[i]] = i;
        build_up(a[i]);        
    }
    val = 0 , root = 0 , root2 = 0;
    DFS(val_id[0] , val_id[0] , 0);
    val = 0;
    DFS2(root , root , 0);
    cout << mp[rev_id[root]] << " " << mp[rev_id[root2]] << " " << val << endl;
}