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

vector<vector<int>> construct(int N , vector<pii> vec , int& ok){
    //cout << "try N = " << N << endl;
    // blue yellow
    // red white
    vector<pii> v = vec;
    vector<vector<int>> ans(N , vector<int>(N));
    vector<pii> red , blue , yellow;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if((i + j) % 2 == 0){
                if(i % 2 == 0)blue.push_back(make_pair(i , j));
            }
            else{
                if(i % 2 == 0)yellow.push_back(make_pair(i , j));
                else red.push_back(make_pair(i , j));
            }
        }
    }
    ok = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        vector<pii>& cells = (red.empty() ? yellow : red);
        while(v[i].x && !cells.empty()){
            --v[i].x;
            auto cur = cells.back();
            cells.pop_back();
            ans[cur.x][cur.y] = v[i].y;
        }
        while(v[i].x && !blue.empty()){
            --v[i].x;
            auto cur = blue.back();
            blue.pop_back();
            ans[cur.x][cur.y] = v[i].y;
        }
        if(v[i].x > 0)ok = 0;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int M , K;
        cin >> M >> K;
        vector<int> cnt(K + 1);
        for(int i = 1; i <= K; ++i)cin >> cnt[i];
        vector<pii> vec;
        for(int i = 1; i <= K; ++i)if(cnt[i] > 0)vec.push_back(make_pair(cnt[i] , i));
        sort(vec.begin() , vec.end() , [&](auto& lhs , auto& rhs){
            return lhs.x > rhs.x;
        });
        int l = 0 , r = sqrt(M) * 6 , N = r , ok = 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if((ll)vec[0].x > (ll)mid * (mid / 2 + mid % 2))ok = 0;
            else if(M > (ll)mid * mid - (ll)(mid / 2) * (mid / 2))ok = 0;
            else construct(mid , vec , ok);
            if(ok){
                N = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << N << endl;
        auto a = construct(N , vec , ok);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}