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
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
string query(int i , int j){
    cout << i << " " << j << endl;
    cout.flush();
    string ans;
    cin >> ans;
    return ans;
}
bool DOWN(string x){
    if(x == "Down")return true;
    if(x == "Down-Left")return true;
    if(x == "Down-Right")return true;
    return false;
}
bool UP(string x){
    if(x == "Up")return true;
    if(x == "Up-Left")return true;
    if(x == "Up-Right")return true;
    return false;
}
bool WIN(string x){
    return x == "Done";
}
bool scan_row(int& x , int& y){
    if(y == 8){
        for(int z = 7; z >= 1; --z){
            y = z;
            string ret = query(x , y);
            if(WIN(ret))return true;
            if(DOWN(ret))return false;
            if(UP(ret))return scan_row(x , y);
        }
        return false;
    }
    for(int z = (y == 1) ? 2 : 1; z <= 8; ++z){
        y = z;
        string ret = query(x , y);
        if(WIN(ret))return true;
        if(DOWN(ret))return false;
        if(UP(ret))return scan_row(x , y);
    }
    return false;
}
bool solve(){
    int x = 1 , y = 1;
    for(; x < 8; ++x){
        if(WIN(query(x , y)))return true;
        if(scan_row(x , y))return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    // the goal is to force the king to be in the conner
    // either (8 , 1) or (8 , 8)
    // to do this, we need to force the king to go down (he should not go up)
    while(t--){
        assert(solve());
    }
} 