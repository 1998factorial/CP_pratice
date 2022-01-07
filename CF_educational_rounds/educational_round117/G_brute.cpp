#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> M;
    vector<int> cnt(M);
    for(int i = 0; i < M; ++i)cin >> cnt[i];
    vector<int> a;
    for(int i = 0; i < M; ++i){
        for(int j = 1; j <= cnt[i]; ++j){
            a.push_back(i + 1);
        }
    }
    int max_score = 0;
    do{
        int score = 0;
        for(int i = 0; i < a.size(); ++i){
            for(int j = i + 1; j < a.size(); ++j){
                if(a[i] == a[j]){
                    score += j - i;
                }
            }
        }
        if(score > max_score){
            max_score = score;
        }
    }while(next_permutation(a.begin() , a.end()));
    cout << "max_score = " << max_score << endl;
    do{
        int score = 0;
        for(int i = 0; i < a.size(); ++i){
            for(int j = i + 1; j < a.size(); ++j){
                if(a[i] == a[j]){
                    score += j - i;
                }
            }
        }
        if(score == max_score){
            for(int i : a){
                cout << i << " ";
            }
            cout << endl;
        }
    }while(next_permutation(a.begin() , a.end()));
}