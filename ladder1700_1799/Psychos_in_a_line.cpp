#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int N , a[maxn] , f[maxn];
int pt[maxn << 2] , ft[maxn << 2];

int query(int tree[] , int l , int r , int x , int y , int id){
    if(l > r || x > y || y < l || x > r)return 0;
    if(l <= x && y <= r){
        return tree[id];
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
        return query(tree , l , r , x , mid , id << 1);
    }
    if(l > mid){
        return query(tree , l , r , mid + 1 , y , id << 1 | 1);
    }
    return max(
        query(tree , l , r , x , mid , id << 1) ,
        query(tree , l , r , mid + 1 , y , id << 1 | 1)
    );
}

void update(int tree[] , int pos , int l , int r , int v , int id){
    if(pos < l || pos > r)return;
    if(pos == l && pos == r){
        tree[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid){
        update(tree , pos , l , mid , v , id << 1);
    }
    else{
        update(tree , pos , mid + 1 , r , v , id << 1 | 1);
    }
    tree[id] = max(tree[id << 1] , tree[id << 1 | 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }  
    for(int i = 1; i <= N; ++i){
        int lg = query(pt , a[i] + 1 , N , 1 , N , 1);
        if(lg != 0){
            f[i] = query(ft , lg + 1 , i - 1 , 1 , N , 1) + 1;
        }
        update(pt , a[i] , 1 , N , i , 1);
        update(ft , i , 1 , N , f[i] , 1);
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i){
        ans = max(ans , f[i]);
    }
    cout << ans << endl;
}