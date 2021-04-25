#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxv = 1e6 + 5;
int N , K , a[maxn] , sum[maxv];

int get(int l , int r){
    return sum[r] - sum[l - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    int minv = maxv;
    memset(sum , 0 , sizeof(sum));
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        ++sum[a[i]];
        minv = min(minv , a[i]);
    }
    // a[i] % minv <= minv , so answer is minv
    if(K >= minv - 1){
        cout << minv << endl;
        exit(0);
    }
    // now, answer could range from K + 1 to minv - 1
    // as a[i] % (K + 1) <= K, and minv > K + 1
    // we can surely make each a[i] % (K + 1) = 0
    for(int i = 1; i < maxv; ++i){
        sum[i] += sum[i - 1];
    }
    int ans = K + 1;
    for(int d = minv; d > K + 1; --d){
        // check if d works
        int total = 0;
        // check weather number of pts fall in [d , d + K] U [2d , 2d + K] U ...
        // is at least N
        for(int nd = d; nd < maxv; nd += d){
            int l = nd;
            int r = min(maxv - 1 , l + K);
            total += get(l , r);
        }
        if(total >= N){
            ans = d;
            break;
        }
    }
    cout << ans << endl;
}