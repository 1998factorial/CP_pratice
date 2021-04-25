#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    int N = 10;
    srand(time(NULL));
    vector<int> a;
    for(int i = 1; i <= N; ++i)a.push_back(i);
    shuffle(a.begin(), a.end(), rng);
    cout << N << endl;
    for(int i : a)cout << i << " ";
    cout << endl;
}