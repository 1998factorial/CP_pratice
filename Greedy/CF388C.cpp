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
// if all evens, then the best we can do is
// A get first half for each pile and B get all remaining
// otherwise, A get one largest middle one
// then B get the second largest middle one 
// and so on (change parity means the person who is about to start can choose which pile to start with)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> cards;
    for(int i = 0; i < N; ++i){
        int sz;
        cin >> sz;
        vector<int> a(sz);
        for(int j = 0; j < sz; ++j)cin >> a[j];
        cards.push_back(a);
    }
    int score1 = 0 , score2 = 0;
    vector<int> middles;
    for(int i = 0; i < N; ++i){
        int sz = cards[i].size();
        if(sz & 1){
            middles.push_back(cards[i][sz / 2]);
            for(int j = 0; j < sz / 2; ++j){
                score1 += cards[i][j];
            }
            for(int j = sz - 1; j > sz / 2; --j){
                score2 += cards[i][j];
            }
        }
        else{
            for(int j = 0; j < sz / 2; ++j){
                score1 += cards[i][j];
            }
            for(int j = sz - 1; j >= sz / 2; --j){
                score2 += cards[i][j];
            }
        }
    }
    sort(middles.begin() , middles.end());
    reverse(middles.begin() , middles.end());
    for(int i = 0; i < middles.size(); ++i){
        if(i & 1){
            score2 += middles[i];
        }
        else{
            score1 += middles[i];
        }
    }
    cout << score1 << " " << score2 << endl;
}
