#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int N , M;
int a[maxn];
struct node {
    int lz , cnt[2];
}; 
node tree[21][maxn << 2];

void build(int bit , int l , int r , int id){
    if(l == r){
        tree[bit][id].lz = 0;
        tree[bit][id].cnt[0] = tree[bit][id].cnt[1] = 0;
        if((a[l] >> bit) & 1)++tree[bit][id].cnt[1];
        else ++tree[bit][id].cnt[0];
    }
    else{
        int mid = (l + r) >> 1;
        build(bit , l , mid , id << 1);
        build(bit , mid + 1 , r , id << 1 | 1);
        tree[bit][id].lz = 0;
        for(int i = 0; i < 2; ++i){
            tree[bit][id].cnt[i] = tree[bit][id << 1].cnt[i] + tree[bit][id << 1 | 1].cnt[i];
        }
    }
}

void push_down(int bit , int l , int r , int id){
    if(l < r && tree[bit][id].lz){
        swap(tree[bit][id << 1].cnt[0] , tree[bit][id << 1].cnt[1]);
        swap(tree[bit][id << 1 | 1].cnt[0] , tree[bit][id << 1 | 1].cnt[1]);
        tree[bit][id << 1].lz ^= tree[bit][id].lz;
        tree[bit][id << 1 | 1].lz ^= tree[bit][id].lz;
        tree[bit][id].lz = 0;
    }
}

void update(int bit , int l , int r , int x , int y , int id){ // revert 0 and 1 in [l , r]
    if(l > r || x > y || r < x || l > y)return;
    push_down(bit , x , y , id);
    if(l <= x && y <= r){
        tree[bit][id].lz = 1;
        swap(tree[bit][id].cnt[0] , tree[bit][id].cnt[1]);
        return;
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
        update(bit , l , r , x , mid , id << 1);
    }
    else if(l > mid){
        update(bit , l , r , mid + 1 , y , id << 1 | 1);
    }
    else{
        update(bit , l , r , x , mid , id << 1);
        update(bit , l , r , mid + 1 , y , id << 1 | 1);
    }
    for(int i = 0; i < 2; ++i){
        tree[bit][id].cnt[i] = tree[bit][id << 1].cnt[i] + tree[bit][id << 1 | 1].cnt[i];
    }
}

int query(int bit , int l , int r , int x , int y , int id){
    if(l > r || x > y || y < l || x > r)return 0;
    push_down(bit , x , y , id);
    if(l <= x && y <= r){
        return tree[bit][id].cnt[1];
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
        return query(bit , l , r , x , mid , id << 1);
    }
    if(l > mid){
        return query(bit , l , r , mid + 1 , y , id << 1 | 1);
    }
    return
        query(bit , l , r , x , mid , id << 1) + 
        query(bit , l , r , mid + 1 , y , id << 1 | 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < 20; ++j){
        build(j , 1 , N , 1);
    }
    cin >> M;
    for(int i = 1; i <= M; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int l , r;
            cin >> l >> r;
            ll ans = 0;
            for(int j = 0; j < 20; ++j){
                ans += (ll)query(j , l , r , 1 , N , 1) * (1ll << j);
            }
            cout << ans << endl;
        }
        else if(t == 2){
            int l , r , x;
            cin >> l >> r >> x;
            for(int j = 0; j < 20; ++j){
                if((x >> j) & 1){
                    update(j , l , r , 1 , N , 1);
                }
            }
        }
    }
}