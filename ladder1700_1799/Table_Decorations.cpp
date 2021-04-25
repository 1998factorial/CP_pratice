#include <bits/stdc++.h>
using namespace std;
int cnt[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> cnt[0] >> cnt[1] >> cnt[2];
    sort(cnt , cnt + 3);
    if(cnt[2] >= ((long long)cnt[0] + cnt[1]) * 2){
        // here, cnt[2] is very large, so we use 2 of it each time
        cout << (long long)cnt[0] + cnt[1] << endl;
    }
    else{
        // in this case, each time, we take 2 from the largest cnt
        // and take 1 from the second largest
        // this is optimal, as each time we take 3, and will eventually 
        // left with sum % 3, which is the best we can do
        cout << ((long long)cnt[0] + cnt[1] + cnt[2]) / 3 << endl;
    }
}