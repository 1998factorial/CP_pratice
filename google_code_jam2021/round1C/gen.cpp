#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e17 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    int N = 10000;
    cout << N << endl;
    for(int i = 1; i <= N; ++i){
        long long x = 1e17 + rand() % mod;
        cout << x << endl;
    }
}