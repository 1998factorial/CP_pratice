#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
vector<pii> ans;
int sz[505] , N;
int ask(vector<int> S , vector<int> T , int v){
    cout << (int)S.size() << endl;
    for(int i : S)cout << i << " ";
    cout << endl;
    cout << (int)T.size() << endl;
    for(int i : T)cout << i << " ";
    cout << endl;
    cout << v << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
void answer(){
    cout << "ANSWER" << endl;
    for(auto e : ans){
        cout << e.x << " " << e.y << endl;
    }
    cout.flush();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    // root = 1
    sz[1] = N;
    // compute each subtree size
    for(int i = 2; i <= N; ++i){
        vector<int> S , T;
        S.push_back(1);
        for(int j = 1; j <= N; ++j){
            if(j != 1)T.push_back(j);
        }
        sz[i] = ask(S , T , i);
    }
    vector<int> id;
    for(int i = 1; i <= N; ++i){
        id.push_back(i);
    }
    sort(id.begin() , id.end() , [&](int& l , int& r){
        return sz[l] < sz[r];
    });
    // for each node, try to find out its direct parent
    // sorted by size, this means i < j , i can not be j's ancestor
    vector<int> fa_undecided;
    for(int t = 0; t < N; ++t){
        int i = id[t];
        if(!fa_undecided.empty()){
            int n_direct_child = ask({1} , fa_undecided , i);
            for(int j = 1; j <= n_direct_child; ++j){
                int l = 0 , r = fa_undecided.size() - 1 , child = -1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    vector<int> S;
                    for(int k = 0; k <= mid; ++k){
                        S.push_back(fa_undecided[k]);
                    }
                    if(ask({1} , S , i)){
                        r = mid - 1;
                        child = fa_undecided[mid];
                    }
                    else{
                        l = mid + 1;
                    }
                }
                if(~child){
                    ans.push_back({i , child});
                }
                vector<int> nex;
                for(int x : fa_undecided){
                    if(x != child){
                        nex.push_back(x);
                    }
                } 
                fa_undecided = nex;
            }
        }
        fa_undecided.push_back(i);
    }
    answer();
} 