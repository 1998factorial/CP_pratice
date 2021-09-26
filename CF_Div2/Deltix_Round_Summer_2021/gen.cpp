#include <bits/stdc++.h>
using namespace std;

int main(){
    int N = 16000;
    for(int i = 0; i < N; ++i){
        char a = 'a' + (i % 3);
        cout << a;
    }
    cout << endl;
}