#include <bits/stdc++.h>
using namespace std;
int N , K;

double solve(vector<int> t) {
    sort(t.begin() , t.end());
    vector<int> half;
    int v = t[0] - 1;
    if(v >= 1){
        half.push_back(v);
    }
    v = K - t.back();
    if(v >= 1){
        half.push_back(v);
    }
    for(int i = 0; i < N - 1; ++i){
        if(t[i + 1] - t[i] < 2)continue;
        half.push_back((t[i + 1] - t[i]) / 2);
    }
    sort(half.begin(), half.end());
    int max_two = 0;
    if(half.size() >= 1)max_two += half[half.size() - 1];
    if(half.size() >= 2)max_two += half[half.size() - 2];
    int max_single = 0;
    for(int i = 0; i < N - 1; ++i){
        max_single = max(max_single , t[i + 1] - t[i] - 1);
    }
    double ret = (double)max(max_single , max_two) / (double)K;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for(int kase = 1; kase <= t; ++kase){
        cin >> N >> K;
        vector<int> a(N);
        for(int j = 0; j < N; ++j){
            cin >> a[j];
        }
        double ret = solve(a);
        cout << "Case #" << kase << ": " << ret << endl;
    }
    return 0;
}