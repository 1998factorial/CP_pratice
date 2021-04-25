#include <bits/stdc++.h>
using namespace std;

int B , a[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> B;
    for(int i = 1; i <= 9; ++i){
        cin >> a[i];
    }
    int minv = a[1];
    for(int i = 1; i <= 9; ++i){
        minv = min(minv , a[i]);
    }
    int N = B / minv;
    if(N == 0){
        cout << -1 << endl;
        exit(0);
    }
    // construct length N
    for(int i = 1; i <= N; ++i){
        for(int j = 9; j >= 1; --j){
            if(B - a[j] >= (N - i) * minv){
                cout << j;
                B -= a[j];
                break;
            }
        }
    }
    cout << endl;
}