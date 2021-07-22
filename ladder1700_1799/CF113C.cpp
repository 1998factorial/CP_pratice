#include <bits/stdc++.h>
using namespace std;
int L , R;
const int maxn = 3e8 + 5;
bitset<maxn> vis;
// answer is the number of x that is in [L , R],
// that is prime, and either = 2 or = 4k + 1

void pre(){
    vis[1] = 1;
    for(int i = 3; (long long)i * i < maxn; i += 2){
        if(!vis[i]){    
            for(int j = 2 * i; j < maxn; j += i){
                vis[j] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> L >> R;
    int ans = 0;
    pre();
    if(L <= 2 && 2 <= R)++ans;
    int start = L;
    if(L % 4 == 0)start += 1; 
    if(L % 4 == 2)start += 3;
    if(L % 4 == 3)start += 2;
    for(int i = start; i <= R; i += 4){
        if(!vis[i])++ans;
    }
    cout << ans << endl;
}   