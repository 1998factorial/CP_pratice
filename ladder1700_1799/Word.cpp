#include <bits/stdc++.h>
using namespace std;

int UP(string& a){
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] >= 'a' && a[i] <= 'z'){
            int c = a[i] - 'a';
            a[i] = 'A' + c;
            ++cnt;
        }
    }
    return cnt;
}

int DOWN(string& a){
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            int c = a[i] - 'A';
            a[i] = 'a' + c;
            ++cnt;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    string s;
    cin >> s;
    string a = s , b = s;
    if(DOWN(a) <= UP(b)){
        cout << a << endl;
    }
    else{
        cout << b << endl;
    }
}

