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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pii> pt(N);
    vector<int> ans(N) , ord(N);
    for(int i = 0; i < N; ++i)cin >> pt[i].x >> pt[i].y , ord[i] = i;
    sort(ord.begin() , ord.end() , [&](auto& l , auto& r){
        return pt[l].x < pt[r].x;
    });
    int step = 1000 , lim = 1000000 , i = 0 , cnt = 0;
    for(int start = step , c = 0; start <= lim; start += step , c ^= 1){
        vector<int> candidates;
        while(i < N && pt[ord[i]].x <= start){
            candidates.push_back(ord[i]);
            ++i;
        }
        sort(candidates.begin() , candidates.end() , [&](auto& l , auto& r){
            return pt[l].y < pt[r].y;
        });
        if(c){
            reverse(candidates.begin() , candidates.end());
        }
        for(int i : candidates){
            ans[i] = cnt++;
        }
    }
    vector<int> bid(N);
    for(int i = 0; i < N; ++i)bid[ans[i]] = i;
    for(int i : bid)cout << i + 1 << " ";
    cout << endl;
    ll dis = 0;
    for(i = 0; i + 1 < N; ++i){
        dis += abs(pt[bid[i]].x - pt[bid[i + 1]].x) + abs(pt[bid[i]].y - pt[bid[i + 1]].y);
    }
    assert(dis <= 2500000000);
}