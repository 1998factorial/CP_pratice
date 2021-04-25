#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const int maxn = 1e5 + 10;
int N , Q , depth[maxn] , L[maxn] , R[maxn] , tot;
vector<int> g[maxn];

struct min_lazy_tree{

    struct node{
        ll val , lazy;
        node(){}
        node(ll v , ll z) : val(v) , lazy(z) {}
    };

    node tree[maxn << 2];

    void push_down(int l , int r , int id){
        if(l > r)return;
        if(tree[id].lazy != 0 && l < r){
            tree[id << 1].lazy += tree[id].lazy;
			tree[id << 1 | 1].lazy += tree[id].lazy;
			tree[id << 1].val += tree[id].lazy;
			tree[id << 1 | 1].val += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }

    node merge(node l , node r){
        node ret(0 , 0);
        if(l.val > r.val){
            ret.val = l.val;
        }
        else{
            ret.val = r.val;
        }
        return ret;
    }

    void build(int l , int r , int id){
        if(l > r)return;
        if(l == r){
            tree[id].val = 0;
            tree[id].lazy = 0;
        }
        else{
            int mid = (l + r) >> 1;
            build(l , mid , id << 1);
            build(mid + 1 , r , id << 1 | 1);
            tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
        }
    }

    void update(int l , int r , int x , int y , int id , ll v){ // support range update
        if(l > r || x > y || r < x || l > y)return;
        push_down(x , y , id);
        if(l <= x && y <= r){
            tree[id].val += v;
            tree[id].lazy += v;
            return;
        }
        int mid = (x + y) >> 1;
        if(r <= mid){
            update(l , r , x , mid , id << 1 , v);
        }
        else if(l > mid){
            update(l , r , mid + 1 , y , id << 1 | 1 , v);
        }
        else{
            update(l , r , x , mid , id << 1 , v);
            update(l , r , mid + 1 , y , id << 1 | 1 , v);
        }
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }

    ll query(int pos , int l , int r , int id){
        if(pos < l || pos > r || l > r)return -INF;
        push_down(l , r , id);
        if(pos == l && pos == r){
            return tree[id].val;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid){
            return query(pos , l , mid , id << 1);
        }
        return query(pos , mid + 1 , r , id << 1 | 1);
    }

} chain , depths;

void DFS(int v , int p , int d){
    depth[v] = d;
    L[v] = ++tot;
    for(int nv : g[v]){
        if(nv != p){
            DFS(nv , v , d + 1);
        }
    }
    R[v] = tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 1; i < N; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tot = 0;
    DFS(1 , 1 , 1);
    chain.build(1 , tot , 1);
    depths.build(1 , tot , 1);
    while(Q--){
        int t;
        cin >> t;
        if(t == 0){
            int v , x , d;
            cin >> v >> x >> d;
            if(depth[v] - d > 1){
                // will not touch node 1
                chain.update(L[v] - d , L[v] - 1 , 1 , tot , 1 , x);
                chain.update(L[v] , min(R[v] , L[v] + d) , 1 , tot , 1 , x);
            }
            else{
                // will touch node 1, and might have some extention
                // to other chains
                int up = d - depth[v] + 2;
                depths.update(1 , up , 1 , tot , 1 , x);
                if(up < depth[v]){
                    chain.update(L[v] - (depth[v] - up - 1) , min(R[v] , L[v] + d) , 1 , tot , 1 , x);
                }
                else{
                    chain.update(L[v] + (up - depth[v] + 1) , min(R[v] , L[v] + d) , 1 , tot , 1 , x);
                }
            }
        }
        else{
            int v;
            cin >> v;
            cout << chain.query(L[v] , 1 , tot , 1) + depths.query(depth[v] , 1 , tot , 1) << endl;
        }
    }
}