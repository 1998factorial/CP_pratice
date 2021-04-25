#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int N , M , a[maxn];
struct node {
    ll sum;
    array<int , 2> maxv; // (value , position)
};
node tree[maxn << 2];

node merge(node lhs , node rhs){
    node ret;
    ret.sum = lhs.sum + rhs.sum;
    ret.maxv = max(lhs.maxv , rhs.maxv);
    return ret;
}

void build(int l , int r , int id){
    if(l == r){
        tree[id].maxv = {a[l] , l};
        tree[id].sum = a[l];
    }
    else{
        int mid = (l + r) >> 1;
        build(l , mid , id << 1);
        build(mid + 1 , r , id << 1 | 1);
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }
}

void point_update(int pos , int l , int r , int v , int id){
    if(pos < l || pos > r || l > r)return;
    if(pos == l && pos == r){
        tree[id].sum = v;
        tree[id].maxv = {v , pos};
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid){
        point_update(pos , l , mid , v , id << 1);
    }
    else{
        point_update(pos , mid + 1 , r , v , id << 1 | 1);
    }
    tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
}

array<int , 2> query_max(int l , int r , int x , int y , int id){
    if(l > r || x > y || y < l || x > r)return {0 , 0};
    if(l <= x && y <= r){
        return tree[id].maxv;
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
        return query_max(l , r , x , mid , id << 1);
    }
    if(l > mid){
        return query_max(l , r , mid + 1 , y , id << 1 | 1);
    }
    return max(
            query_max(l , r , x , mid , id << 1) ,
            query_max(l , r , mid + 1 , y , id << 1 | 1)
        );
}

ll query_sum(int l , int r , int x , int y , int id){
    if(l > r || x > y || y < l || x > r)return 0;
    if(l <= x && y <= r){
        return tree[id].sum;
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
        return query_sum(l , r , x , mid , id << 1);
    }
    if(l > mid){
        return query_sum(l , r , mid + 1 , y , id << 1 | 1);
    }
    return
        query_sum(l , r , x , mid , id << 1) + 
        query_sum(l , r , mid + 1 , y , id << 1 | 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    build(1 , N , 1);
    for(int q = 1; q <= M; ++q){
        int t;
        cin >> t;
        if(t == 1){
            int l , r;
            cin >> l >> r;
            // sum of a[l] ... a[r]
            cout << query_sum(l , r , 1 , N , 1) << endl;
        }
        else if(t == 2){
            int l , r , x;
            cin >> l >> r >> x;
            // a[i] %= x, for all x in [l , r]
            for(;;){
                auto ret = query_max(l , r , 1 , N , 1);
                if(ret[0] < x)break;
                point_update(ret[1] , 1 , N , ret[0] % x , 1);
            }
        }
        else if(t == 3){
            int pos , x;
            cin >> pos >> x;
            // a[pos] = x
            point_update(pos , 1 , N , x , 1);
        }
    }
}