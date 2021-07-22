#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;
const __int128 inf = 5e18;

string toString(__int128 a){
    string ans = "";
    while(a > 0){
        ans += '0' + a % 10;
        a /= 10;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

void check(__int128& ans , __int128 val , ll a){
    if(val > inf)return;
    if(val <= 0)return;
    __int128 sum = val;
    do{
        ++val;
        __int128 tmp = val;
        while(tmp > 0){
            tmp /= 10;
            sum *= 10;
        }
        sum += val;
    }while(sum <= a);
    if(ans == -1 || ans > sum){
        ans = sum;
    }
}

string solve(){
    ll a;
    cin >> a;
    __int128 ans = -1;
    string aa = to_string(a);
    int sz = aa.size();
    __int128 ones = 1;
    for(int len = 1; len <= sz; ++len){
        __int128 val = 0;
        for(int j = 0; j < len; ++j)val = val * 10 + (aa[j] - '0');
        for(int j = 0; j <= 50; ++j){
            check(ans , val + j , a);
        }
        for(int j = 1; j <= 50; ++j){
            check(ans , ones - j , a);
            check(ans , ones + j , a);
        }
        ones *= 10;
    }
    for(int j = 1; j <= 50; ++j){
        check(ans , ones - j , a);
        check(ans , ones + j , a);
    }
    assert(ans >= 0);
    return toString(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int kase = 1; kase <= t; ++kase){
        cout << "Case #" << kase << ": " << solve() << endl;
    }
}