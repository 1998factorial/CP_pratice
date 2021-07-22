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
int a[maxn] , N , ans[maxn] , v[maxn];
/* 
    answer for pos i = max{
        (cnt[>= a[i]] - cnt[< a[i]] + 1) / 2 , (cnt[<= a[i]] - cnt[> a[i]]) / 2
    }
*/   
struct node{
    int L , R , best , sum;
} tree[maxn << 2];
node merge(const node& left , const node& right){
    node ret;
    ret.sum = left.sum + right.sum;
    ret.L = max(left.L , left.sum + right.L);
    ret.R = max(right.R , left.R + right.sum);
    ret.best = max(left.best , right.best);
    ret.best = max(ret.best , left.R + right.L);
    return ret;
} 
void build(int l , int r , int id){
    if(l == r){
        tree[id].L = v[r];
        tree[id].R = v[r];
        tree[id].best = v[r];
        tree[id].sum = v[r];
    }
    else{
        int mid = (l + r) >> 1;
        build(l , mid , id << 1);
        build(mid + 1 , r , id << 1 | 1);
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }
}
void update(int pos , int l , int r , int id , int val){
    // support point update
    if(pos < l || pos > r)return;
    if(pos == l && r == pos){
        tree[id].sum = val;
        tree[id].L = tree[id].R = tree[id].best = val;//max(0 , val);
    }
    else{
        int m = (l + r) >> 1;
        if(pos <= m){
            update(pos , l , m , id << 1 , val);
        }
        else{
            update(pos , m + 1 , r , id << 1 | 1 , val);
        }
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }
}
node query(int l , int r , int x , int y , int id){
    // range query
    if(l <= x && y <= r){
        return tree[id];
    }
    int mid = (x + y) >> 1;
    node ret;
    if(mid >= r){
        ret = query(l , r , x , mid , id << 1);
        return ret;
    }
    if(mid < l){
        ret = query(l , r , mid + 1 , y , id << 1 | 1);
        return ret;
    }
    ret = merge(query(l , r , x , mid , id << 1) , query(l , r , mid + 1 , y , id << 1 | 1));
    return ret;
}
void solve1(){
    // solve for (cnt[>= a[i]] - cnt[< a[i]] + 1) / 2
    vector<int> ids(N);
    for(int i = 0; i < N; ++i)ids[i] = i + 1;
    sort(ids.begin() , ids.end() , [&](auto& l , auto& r){
        return a[l] < a[r];
    });
    for(int i = 1; i <= N; ++i)v[i] = 1;
    build(1 , N , 1);
    for(int i = 0 , j = 0; i < N; ++i){
        update(ids[i] , 1 , N , 1 , inf32); // forcing the answer to include v[ids[i]]
        while(j < i && a[ids[j]] < a[ids[i]]){
            v[ids[j]] = -1;
            //update in segtree
            update(ids[j] , 1 , N , 1 , v[ids[j]]);
            ++j;
        }
        node ret = query(1 , N , 1 , N , 1);
        ans[ids[i]] = max(ans[ids[i]] , (ret.best - inf32 + 1) / 2); // query here
        update(ids[i] , 1 , N , 1 , v[ids[i]]);
    }
}   
void solve2(){
    // solve for (cnt[<= a[i]] - cnt[> a[i]]) / 2
    vector<int> ids(N);
    for(int i = 0; i < N; ++i)ids[i] = i + 1;
    sort(ids.begin() , ids.end() , [&](auto& l , auto& r){
        return a[l] > a[r];
    });
    for(int i = 1; i <= N; ++i)v[i] = 1;
    build(1 , N , 1);
    for(int i = 0 , j = 0; i < N; ++i){
        update(ids[i] , 1 , N , 1 , inf32);
        while(j < i && a[ids[j]] > a[ids[i]]){
            v[ids[j]] = -1;
            //update in segtree
            update(ids[j] , 1 , N , 1 , v[ids[j]]);
            ++j;
        }
        node ret = query(1 , N , 1 , N , 1);
        ans[ids[i]] = max(ans[ids[i]] , (ret.best - inf32) / 2); // query here
        update(ids[i] , 1 , N , 1 , v[ids[i]]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    solve1();
    solve2();
    for(int i = 1; i <= N; ++i)cout << ans[i] << " ";
    cout << endl;
}