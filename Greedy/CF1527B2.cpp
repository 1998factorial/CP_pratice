#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 35005;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string a;
        int N; 
        cin >> N;
        cin >> a;
        int is_palindrome = 1;
        for(int i = 0; i < N / 2; ++i){
            if(a[i] != a[N - i - 1])is_palindrome = 0;
        }
        if(is_palindrome){
            int nzeros = 0;
            for(int i = 0; i < N; ++i){
                if(a[i] == '0'){
                    ++nzeros;
                }
            }
            if(nzeros == 0){
                cout << "DRAW" << endl;
                continue;
            }
            if(nzeros % 2 == 0){
                // 1001
                // 1101 A1
                // 1011 B0
                // 1111 A1
                cout << "BOB" << endl;
                continue;
            }
            if(a[N / 2] == '0' && nzeros > 1){
                // 10001
                // 10101 A1
                // 10111 B1
                // 11101 A0
                // 11111 B1
                cout << "ALICE" << endl;
                continue;
            }
            cout << "BOB" << endl;
        }
        else{
            // when the string is palindrome and nzeros > 1 & nzeros % 2 = 1
            // Alice wins
            int nzeros = 0;
            for(int i = 0; i < N; ++i){
                if(a[i] == '0'){
                    ++nzeros;
                }
            }
            if(nzeros == 0){
                cout << "DRAW" << endl;
                continue;
            }
            if(N % 2 == 1 && nzeros == 2 && a[N / 2] == '0'){
                // 1110101
                cout << "DRAW" << endl;
                continue;
            }
            // if Bob is one step aways from making string a 
            // palindrome with even number of zeros or one zero left
            // Alice does that step first and forcing Bob to lose
            cout << "ALICE" << endl;
        }
    }
}