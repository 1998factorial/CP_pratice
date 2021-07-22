#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , M;
        cin >> N >> M;
        vector<int> X(N) , r(N) , ans(N , -1) , ord[2];
        vector<char> dr(N);
        for(int i = 0; i < N; ++i){
            cin >> X[i];
            ord[X[i] % 2].push_back(i);
        }
        for(int i = 0; i < N; ++i){
            cin >> dr[i];
            if(dr[i] == 'R')r[i] = 1;
        }
        for(int i = 0; i < 2; ++i){
            sort(ord[i].begin() , ord[i].end() , [&](int l , int r){
                return X[r] < X[l];
            });
        }
        // first L and R will have some collision
        for(int j = 0; j < 2; ++j){
            deque<int> L , R;
            // for each R , we need to find the closest L to it
            for(int i : ord[j]){
                if(r[i]){
                    if(!L.empty()){
                        int v = L.front();
                        L.pop_front();
                        ans[i] = ans[v] = (X[v] - X[i]) / 2;
                    }
                }
                else{
                    L.push_front(i);
                }
            }
        }
        // now we handle the L L or R R collision
        for(int j = 0; j < 2; ++j){
            deque<int> R;
            // R first
            for(int i : ord[j]){
                if(~ans[i])continue;
                if(!r[i])continue;
                if(!R.empty()){
                    int v = R.front();
                    R.pop_front();
                    ans[i] = ans[v] = (M - X[v] + M - X[i]) / 2;
                }
                else{
                    R.push_front(i);
                }
            }
            deque<int> L;
            // L then
            reverse(ord[j].begin() , ord[j].end());
            for(int i : ord[j]){
                if(~ans[i])continue;
                if(r[i])continue;
                if(!L.empty()){
                    int v = L.front();
                    L.pop_front();
                    ans[i] = ans[v] = (X[i] + X[v]) / 2;
                }
                else{
                    L.push_front(i);
                }
            }
            // if we are left with exactly one L and one R
            // we have a match here
            if(!L.empty() && !R.empty()){
                int x = L.front();
                int y = R.front();
                // looks like ....<-x.....y->....
                ans[x] = ans[y] = (M - X[y] + M + X[x]) / 2;
            }
        }
        for(int i : ans)cout << i << " ";
        cout << endl;
    }
}


