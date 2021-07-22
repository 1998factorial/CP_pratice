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
int table_max[25][maxn];
int table_min[25][maxn];
int logs[maxn];
int query_max(int l, int r) {
    if(l > r)return -inf32;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return max(table_max[logs[len]][l] , table_max[logs[len]][pos]);
}
int query_min(int l, int r) {
    if(l > r)return inf32;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return min(table_min[logs[len]][l] , table_min[logs[len]][pos]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 2; i < maxn; ++i){
        logs[i] = logs[i / 2] + 1;
    }
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for(int i = 1; i <= N; ++i)cin >> a[i];
        for(int i = 1; i <= N; ++i){
            table_max[0][i] = table_min[0][i] = a[i];
        }
        for(int i = 1; i <= logs[N]; ++i){
            int prel = (1 << (i - 1));
            for(int j = 1; j <= N; ++j){
                if(j + prel <= N){
                    table_max[i][j] = max(table_max[i - 1][j] , table_max[i - 1][j + prel]);
                    table_min[i][j] = min(table_min[i - 1][j] , table_min[i - 1][j + prel]);
                }
                else{
                    table_max[i][j] = table_max[i - 1][j];
                    table_min[i][j] = table_min[i - 1][j];
                }
            }
        }
        vector<int> left_less(N + 1 , -1) , right_greater(N + 1 , -1);
        // i < j < k , a[i] <= a[j] <= a[k]
        // i < j < k , a[i] >= a[j] >= a[k]
        // then bad array
        vector<int> left_greater(N + 1 , -1) , right_less(N + 1 , -1);
        vector<int> L(N + 1 , -1);
        for(int i = 1; i <= N; ++i){
            int l = 1 , r = i - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(query_min(mid , i - 1) <= a[i]){
                    left_less[i] = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            l = i + 1 , r = N;
            while(l <= r){
                int mid = (l + r) / 2;
                if(query_max(i + 1 , mid) >= a[i]){
                    right_greater[i] = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if(~left_less[i] && ~right_greater[i]){
                L[right_greater[i]] = max(L[right_greater[i]] , left_less[i]);
            }
            l = 1 , r = i - 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(query_max(mid , i - 1) >= a[i]){
                    left_greater[i] = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            l = i + 1 , r = N;
            while(l <= r){
                int mid = (l + r) / 2;
                if(query_min(i + 1 , mid) <= a[i]){
                    right_less[i] = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if(~left_greater[i] && ~right_less[i]){
                L[right_less[i]] = max(L[right_less[i]] , left_greater[i]);
            }
        }
        ll ans = 0;
        for(int i = 1; i <= N; ++i){
            L[i] = max(L[i] , L[i - 1]);
            if(L[i] == -1)ans += i;
            else ans += i - L[i];
        }
        cout << ans << endl;
    }
}   
// my method is too complicated and its not the intended solution
// the intended solution is: first observe, we need to have an array is good if
// there is no triple of max(a[i] , a[k]) >= a[j] >= min(a[i] , a[k]) , for i < j < k
// one can show that, for all length >= 5 arrays, there must exist at least one bad triple
// so we only need to brute force the length <= 4 arrays