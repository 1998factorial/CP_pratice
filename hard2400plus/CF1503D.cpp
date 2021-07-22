#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int , int> pii;
const int maxn = 2e5 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pii> cards(N);
    int maxv = 0;
    for(auto& card : cards){
        cin >> card.x >> card.y;
        maxv = max(maxv , min(card.x , card.y));
    }
    for(auto& card : cards){
        if(max(card.x , card.y) < maxv){
            cout << -1 << endl;
            exit(0); 
        }
    }
    // now we know that for all i
    // max(a[i] , b[i]) in [N+1,2N]
    // min(a[i] , b[i]) in [1,N]
    vector<int> f(N + 1) , cost(N + 1);
    for(auto& card : cards){
        if(card.x > card.y)cost[card.y] = 1 , swap(card.x , card.y);
        f[card.x] = card.y; // the cost to make the smaller one on top
    }
    // now if there is a solution, then we can divide [f[1] .. f[N]] into
    // 2 decreasing sequences
    // for i's in first sequence, will be on top, else , not on top
    // but how do we ensure the cost is minimised?
    vector<int> sufix_max(N + 2 , 0) , prefix_min(N + 2 , 2 * N + 100);
    for(int i = N; i >= 1; --i){
        sufix_max[i] = max(sufix_max[i + 1] , f[i]);
    }
    for(int i = 1; i <= N; ++i){
        prefix_min[i] = min(prefix_min[i - 1] , f[i]);
    }
    // divide [1 ... N] into segments by f[i]
    // if prefix_min[i] > sufix_max[i + 1] , then we know 
    // nothing in [i + 1..N] can go after anything in [1..i]
    // therefore, we can split [1..N] into these 2 independent segments
    vector<int> up , down;
    int cost_up = 0 , cost_down = 0 , ans = 0;
    for(int i = 1; i <= N; ++i){
        if(up.empty() || up.back() > f[i]){
            up.push_back(f[i]);
            cost_up += cost[i];
        }
        else if(down.empty() || down.back() > f[i]){
            down.push_back(f[i]);
            cost_down += cost[i];
        }
        else{
            cout << -1 << endl;
            exit(0);
        }
        if(i == N || prefix_min[i] > sufix_max[i + 1]){ // we are at a seperator now
            int cost_for_first_up = cost_up + down.size() - cost_down;
            int cost_for_first_down = (int)down.size() + up.size() - cost_for_first_up;
            ans += min(cost_for_first_up , cost_for_first_down);
            // note that we can filp the opposite way and reverse the whole segment
            // so we have 2 cases here
            up.clear();
            down.clear();
            cost_up = 0;
            cost_down = 0;
        }
    }
    cout << ans << endl;
}