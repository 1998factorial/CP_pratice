#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;

string construct(int v){
    string ret = "";
    if(v == 0)ret = "0";
    else{
        while(v > 9){
            ret += '9'; 
            v -= 9; 
        }
        ret += ('0' + v);
        reverse(ret.begin() , ret.end());
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> b(N);
    // construct a[0] greedily
    for(int i = 0; i < N; ++i)cin >> b[i];
    string ans = construct(b[0]);
    cout << ans << endl;
    for(int i = 1; i < N; ++i){
        if(b[i] > b[i - 1]){
            // add from least significant digit
            int d = b[i] - b[i - 1];
            int j = ans.size() - 1;
            while(d > 0){
                if(j >= 0){
                    if(ans[j] < '9')++ans[j] , --d;
                    else --j;
                }
                else{
                    break;
                }
            }
            if(d > 0){
                string nans = "";
                nans = construct(d);
                nans += ans;
                ans = nans;
            }
        }
        else{
            // we try to find a least significant place
            // where we can just increase by 1
            // and the less significant places will just be solved 
            // greedily (smallest) on d - 1
            int d = b[i] - b[i - 1] , start = -1;
            for(int j = ans.size() - 1; j >= 0; --j){
                d += ans[j] - '0';
                if(d > 0){
                    start = j - 1;
                    break;
                }
            }
            // 999      27    make it sum to 20
            // 99[] , -7 + 9 = 2 , [][][] , 20
            // 1[][][] , 19
            // 1199
            while(start >= 0 && ans[start] == '9'){
                d += ans[start] - '0';
                --start;
            }
            if(start < 0){
                string sufix = construct(d - 1);
                int sz = sufix.size();
                string nans = "1";
                while(sz < ans.size()){
                    nans += '0';
                    ++sz;
                }
                nans += sufix;
                ans = nans;
            }
            else{
                string nans = "";
                for(int j = 0; j <= start; ++j)nans += ans[j];
                nans.back()++;
                string sufix = construct(d - 1);
                int sz = sufix.size();
                while(sz + start + 1 < ans.size()){
                    nans += '0';
                    ++sz;
                }
                nans += sufix;
                ans = nans;
            }
        }
        cout << ans << endl;
    }
}