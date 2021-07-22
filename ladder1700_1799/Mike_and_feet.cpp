#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int table[25][maxn];
int logs[maxn];
int v[maxn];
int query(int l, int r) {
    if(l > r)return inf32;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return min(table[logs[len]][l] , table[logs[len]][pos]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N + 1) , ord;
    for(int i = 1; i <= N; ++i)cin >> a[i] , ord.push_back(i);
    sort(ord.begin() , ord.end() , [&](int l , int r){
        return a[l] < a[r];
    });
    for(int i = 2; i < maxn; ++i){
        logs[i] = logs[i / 2] + 1;
    }
    for(int i = 1; i <= N; ++i){
        table[0][i] = a[i];
    }
    for(int i = 1; i <= logs[N]; ++i){
        int prel = (1 << (i - 1));
        for(int j = 1; j <= N; ++j){
            if(j + prel <= N){
                table[i][j] = min(table[i - 1][j] , table[i - 1][j + prel]);
            }
            else{
                table[i][j] = table[i - 1][j];
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        int l = 1 , r = i , posl = i;
        while(l <= r){
            int mid = (l + r) / 2;
            if(query(mid , i) >= a[i])posl = mid , r = mid - 1;
            else l = mid + 1;
        }
        int posr = i;
        l = i , r = N;
        while(l <= r){
            int mid = (l + r) / 2;
            if(query(i , mid) >= a[i])posr = mid , l = mid + 1;
            else r = mid - 1;
        }
        int len = posr - posl + 1;
        v[len] = max(v[len] , a[i]);
    }
    for(int i = N; i >= 1; --i){
        v[i] = max(v[i] , v[i + 1]);
    }
    for(int len = 1; len <= N; ++len){
        cout << v[len] << " ";
    }
    cout << endl;
}