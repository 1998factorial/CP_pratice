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
int N , M , a[maxn];
char st[maxn];
struct node{
    int cnt[3][3];
}tree[maxn * 5];
node merge(node l , node r){
    node ans;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            ans.cnt[i][j] = 0;
        }
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            ans.cnt[i][j] = l.cnt[i][j] + r.cnt[i][j];
        }
    }
    return ans;
}
void build(int l , int r , int id){
    if(l == r){
        tree[id].cnt[l % 3][a[l]]++;
    }
    else{
        int mid = (l + r) / 2;
        build(l , mid , id << 1);
        build(mid + 1 , r , id << 1 | 1);
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }
}
node query(int l , int r , int x , int y , int id){
    if(l <= x && y <= r){
        return tree[id];
    }
    int mid = (x + y) >> 1;
    if(r <= mid){
       return query(l , r , x , mid , id << 1);
    }
    if(l > mid){
        return query(l , r , mid + 1 , y , id << 1 | 1);
    }
    return merge(
        query(l , r , x , mid , id << 1) ,
        query(l , r , mid + 1 , y , id << 1 | 1)
    );    
}
int answer(int l , int r){
    int ans = inf32;
    node ret = query(l , r , 1 , N , 1);
    vector<int> v;
    for(int i = 0; i < 3; ++i){
        v.push_back(i);
    }
    do{
        int sum = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(j != v[i]){
                    sum += ret.cnt[i][j];
                }
            }
        }
        ans = min(ans , sum);
    }while(next_permutation(v.begin() , v.end()));
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    cin >> (st + 1);
    for(int i = 1; i <= N; ++i){
        a[i] = st[i] - 'a';
    }
    build(1 , N , 1);
    while(M--){
        int l , r;
        cin >> l >> r;
        cout << answer(l , r) << endl;
    }
}   
