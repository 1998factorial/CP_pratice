#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , tin[maxn] , tout[maxn] , tot , vis[maxn];
vector<int> g[maxn];
ll sz[maxn];

void DFS(int v , int p){
    tin[v] = ++tot;
    sz[v] = 1;
    for(int nv : g[v]){
        if(nv != p){
            DFS(nv , v);
            sz[v] += sz[nv];
        }
    }
    tout[v] = tot;
}

bool insubtree(int v , int u){ // check if u is in v's subtree
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void init(){
    tot = 0;
    for(int i = 0; i < N; ++i)g[i].clear() , sz[i] = tin[i] = tout[i] = vis[i] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        init();
        for(int i = 0; i < N; ++i)g[i].clear();
        for(int i = 1; i < N; ++i){
            int u , v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // #(MEX = x) = #(MEX >= x) - #(MEX >= x + 1)
        DFS(0 , 0);
        ll cur = (ll)N * (N - 1) / 2 , nex = 0 , sum = 1;
        for(int v : g[0]){
            nex += sz[v] * sum;
            sum += sz[v];
        }   
        cout << cur - nex << " ";
        int L = 0 , R = 0;
        for(;;){
            vis[R] = 1;
            for(int v : g[R]){
                if(vis[v])continue;
                if(insubtree(v , 1)){
                    R = v;
                    break;
                }
            }
            if(R == 1)break;
        }
        int nzero = 0;
        for(int v : g[0]){
            if(insubtree(v , 1)){
                nzero = v;
                sum -= sz[v];
                break;
            }
        }
        cur = nex;
        nex = sz[1] * sum;
        cout << cur - nex << " ";
        int left_zeros = 0 , mex = 2;
        for(; mex < N; ++mex){
            if(vis[mex]){
                cur = nex;
                cout << cur - nex << " ";
                continue;
            }
            cur = nex;
            if(insubtree(R , mex)){
                // we need to go down from R to mex
                for(;;){
                    vis[R] = 1;
                    for(int v : g[R]){
                        if(vis[v])continue;
                        if(insubtree(v , mex)){
                            R = v;
                            break;
                        }
                    }
                    if(R == mex)break;
                }
                nex = sum * sz[R];
                cout << cur - nex << " ";
                continue;
            }
            if(insubtree(nzero , mex)){
                left_zeros = 1;
                cout << cur << " ";
                break;
            }
            // here, we go down from L
            for(;;){
                vis[L] = 1;
                for(int v : g[L]){
                    if(vis[v])continue;
                    if(insubtree(v , mex)){
                        L = v;
                        break;
                    }
                }
                if(L == mex)break;
            }
            nex = sz[L] * sz[R];
            cout << cur - nex << " ";
            break;
        }
        //cout << "L = " << L << endl;
        //cout << "R = " << R << endl;
        ++mex;
        if(left_zeros){
            for(; mex <= N; ++mex){
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        for(; mex < N; ++mex){
            if(vis[mex]){
                cur = nex;
                cout << cur - nex << " ";
                continue;
            }
            cur = nex;
            if(insubtree(L , mex)){
                for(;;){
                    vis[L] = 1;
                    for(int v : g[L]){
                        if(vis[v])continue;
                        if(insubtree(v , mex)){
                            L = v;
                            break;
                        }
                    }
                    if(L == mex)break;
                }
                nex = sz[L] * sz[R];
                cout << cur - nex << " ";
                continue;
            }
            if(insubtree(R , mex)){
                for(;;){
                    vis[R] = 1;
                    for(int v : g[R]){
                        if(vis[v])continue;
                        if(insubtree(v , mex)){
                            R = v;
                            break;
                        }
                    }
                    if(R == mex)break;
                }
                nex = sz[L] * sz[R];
                cout << cur - nex << " ";
                continue;
            }
            left_zeros = 1;
            cout << cur << " ";
            ++mex;
            for(; mex <= N; ++mex){
                cout << 0 << " ";
            }
            break;
        }
        if(left_zeros == 0)cout << nex << " ";
        cout << endl;
    }
}

