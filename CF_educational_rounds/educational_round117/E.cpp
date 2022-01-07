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
    int t;
    t = 1;
    while(t--){
        int N , M = 0;
        cin >> N;
        unordered_map<int , int> imp;
        vector<pii> vec(N);
        vector<int> tmp;
        for(int i = 0; i < N; ++i){
            cin >> vec[i].x >> vec[i].y;
            --vec[i].x;
            tmp.push_back(vec[i].x);
        }
        sort(tmp.begin() , tmp.end());
        tmp.erase(unique(tmp.begin() , tmp.end()) , tmp.end());
        M = tmp.size();
        for(auto& p : vec){
            int v = lower_bound(tmp.begin() , tmp.end() , p.x) - tmp.begin();
            imp[v] = p.x;
            p.x = v;
        }
        // we will not pin more than 20 messages
        double E = 0;
        vector<int> ans;
        for(int nmsg = 1; nmsg <= min(20 , M); ++nmsg){
            vector<double> val(M);
            // val[i] = the expected number of ppl seeing message[i], if there are a total of nmsg messages
            for(auto p : vec){
                if(p.y > nmsg)val[p.x] += nmsg;
                else val[p.x] += p.y;
            }
            vector<int> id(M);
            for(int i = 0; i < M; ++i)id[i] = i;
            sort(id.begin() , id.end() , [&](int& l , int& r){
                return val[l] > val[r];
            });
            vector<int> subset;
            double exp_now = 0;
            for(int i = 0; i < nmsg; ++i){
                exp_now += val[id[i]];
                subset.push_back(id[i]);
            }
            exp_now /= nmsg;
            if(E < exp_now){
                E = exp_now;
                ans = subset;
            }
        }
        cout << (int)ans.size() << endl;
        for(int i : ans){
            cout << imp[i] + 1 << " ";
        }
        cout << endl;
    }
}