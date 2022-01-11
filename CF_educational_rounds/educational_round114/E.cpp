#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cout << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
ll mul(ll x,ll y){
    return x*y%mod;
}
ll add(ll x,ll y){
    return ((x+y)%mod+mod)%mod;
}
ll qpow(ll x,ll n){
    ll ret=1ll;
    while(n){
        if(n&1)ret=mul(ret,x);
        x=mul(x,x);
        n>>=1;
    }
    return ret;
}
//case 1: we have 00 or 11
//0001
//1110
//0001
//1110
//case 2: we don't have 00 or 11
//1010
//0101
//0101
//1010
//case 1:2^M-2,case 2:2^N
//answer=[no bad row]*2^(#free row)+[no bad col]*2^(#free col)-[01chess board]-[10chess board]
//row/col is bad if even and odd have same value
int free_col,free_row,all_row_good,all_col_good,matrix_01,matrix_10;
int col[maxv],row[maxv],check[2][2],C[maxv][2][2],R[maxv][2][2];
set<int> bad_col,bad_row;
ll p[maxv];
map<pii,int>a;
void del(int r,int c){
    if(a.count({r,c})){
        int v=a[{r,c}];
        --check[(r+c)&1][v];
        --col[c];
        --row[r];
        if(col[c]==0)++free_col;
        if(row[r]==0)++free_row;
        --C[c][r&1][v];
        --R[r][c&1][v];
        if(
            (C[c][r&1][v]<=0||C[c][1-(r&1)][v]<=0)
            &&
            (C[c][r&1][v^1]<=0||C[c][1-(r&1)][v^1]<=0)
            &&
            (C[c][r&1][v]<=0||C[c][r&1][v^1]<=0)
            &&
            (C[c][1-(r&1)][v]<=0||C[c][1-(r&1)][v^1]<=0)
            )
        {
            if(bad_col.count(c))bad_col.erase(c);
        }
        if(
            (R[r][c&1][v]<=0||R[r][1-(c&1)][v]<=0)
            &&
            (R[r][c&1][v^1]<=0||R[r][1-(c&1)][v^1]<=0)
            &&
            (R[r][c&1][v]<=0||R[r][c&1][v^1]<=0)
            &&
            (R[r][1-(c&1)][v]<=0||R[r][1-(c&1)][v^1]<=0)
            )
        {
            if(bad_row.count(r))bad_row.erase(r);
        }
    }
    a.erase({r,c});
}
void add(int r,int c,int v){
    //given a[r][c]=-1
    ++check[(r+c)&1][v];
    if(col[c]==0)--free_col;
    if(row[r]==0)--free_row;
    ++col[c];
    ++row[r];
    ++C[c][r&1][v];
    ++R[r][c&1][v];
    if(
        (C[c][r&1][v]>0&&C[c][1-(r&1)][v]>0)
        ||
        (C[c][r&1][v^1]>0&&C[c][1-(r&1)][v^1]>0)
        ||
        (C[c][r&1][v]>0&&C[c][r&1][v^1]>0)
        ||
        (C[c][1-(r&1)][v]>0&&C[c][1-(r&1)][v^1]>0)
        ){
        bad_col.insert(c);
    }
    if(
        (R[r][c&1][v]>0&&R[r][1-(c&1)][v]>0)
        ||
        (R[r][c&1][v^1]>0&&R[r][1-(c&1)][v^1]>0)
        ||
        (R[r][c&1][v]>0&&R[r][c&1][v^1]>0)
        ||
        (R[r][1-(c&1)][v]>0&&R[r][1-(c&1)][v^1]>0)
        ){
        bad_row.insert(r);
    }
    a[{r,c}]=v;
}
void upd(){
    matrix_01=(check[0][1]==0&&check[1][0]==0);
    matrix_10=(check[0][0]==0&&check[1][1]==0);
    all_col_good=(bad_col.size()<=0);
    all_row_good=(bad_row.size()<=0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    free_col=M;
    free_row=N;
    all_row_good=1;
    all_col_good=1;
    matrix_01=1;
    matrix_10=1;
    p[0]=1;
    for(int i=1;i<=max(N,M);++i)p[i]=mul(p[i-1],2ll);
    while(K--){
        int x,y,c;
        cin>>x>>y>>c;
        if(c==-1){
            del(x,y);
        }
        else{
            del(x,y);
            add(x,y,c);
        }
        upd();
        ll ans=mul(all_col_good,p[free_col]);
        ans=add(ans,mul(all_row_good,p[free_row]));
        ans=add(ans,-matrix_01);
        ans=add(ans,-matrix_10);
        cout<<ans<<endl;
    }
}   