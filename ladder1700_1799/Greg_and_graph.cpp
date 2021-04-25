#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
int N , a[505][505] , dis[505][505];
bool in[505];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cin >> a[i][j];
        }
    }
    vector<int> d(N);
    for(int i = 0; i < N; ++i)cin >> d[i];
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            dis[i][j] = inf;
        }
    }
    vector<ll> ans;
    reverse(d.begin() , d.end());
    for(int v : d){
        in[v] = 1;
        for(int i = 1; i <= N; ++i){
            dis[v][i] = min(dis[v][i] , a[v][i]);
            dis[i][v] = min(dis[i][v] , a[i][v]);
        }
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                dis[i][j] = min(dis[i][j] , dis[i][v] + dis[v][j]);
            }
        }
        ll sum = 0;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(in[i] && in[j])sum += dis[i][j];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin() , ans.end());
    for(auto i : ans)cout << i << " ";
    cout << endl;
}