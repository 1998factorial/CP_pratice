#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int N , M;
int ones[30][maxn] , ans[maxn] , val[maxn << 2];
vector<array<int , 3>> qs;

void build(int l , int r , int id){
    if(l == r){
        val[id] = ans[l];
    }
    else{
        int mid = (l + r) >> 1;
        build(l , mid , id << 1);
        build(mid + 1 , r , id << 1 | 1);
        val[id] = val[id << 1] & val[id << 1 | 1];
    }
}

int query(int l , int r , int x , int y , int id){
    if(l > r || x > y || y < l || x > r)return 0;
    if(l <= x && y <= r){
        return val[id];
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
        return query(l , r , x , mid , id << 1);
    }
    if(l > mid){
        return query(l , r , mid + 1 , y , id << 1 | 1);
    }
    return
        query(l , r , x , mid , id << 1) &
        query(l , r , mid + 1 , y , id << 1 | 1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int l , r , x;
        cin >> l >> r >> x;
        qs.push_back({l , r , x});
        for(int j = 0; j < 30; ++j){
            if((x >> j) & 1){
                ++ones[j][l];
                --ones[j][r + 1];
            }
        }
    }
    for(int j = 0; j < 30; ++j){
        for(int i = 1; i <= N; ++i){
            ones[j][i] += ones[j][i - 1];
            if(ones[j][i] > 0){
                ans[i] |= (1 << j);
            }
        }
    }
    build(1 , N , 1);
    for(auto e : qs){
        int l = e[0] , r = e[1] , v = e[2];
        if(query(l , r , 1 , N , 1) != v){
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= N; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
}