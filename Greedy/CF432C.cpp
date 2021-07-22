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
    vector<int> a(N + 1) , id(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i] , id[a[i]] = i; 
    vector<int> vis(maxn , 0) , primes;
    for(int i = 2; i <= N; ++i){
        if(vis[i])continue;
        primes.push_back(i);
        for(int j = i; j <= N; j += i){
            vis[j] = 1;
        }
    }
    auto sswap = [&](int l , int r){
        swap(id[a[l]] , id[a[r]]);
        swap(a[l] , a[r]);
    };
    vector<pii> ans;
    for(int i = 1; i <= N; ++i){
        int cur = id[i];
        if(cur < i){
            while(i - cur + 1 < 1){
                int l = 0 , r = primes.size() - 1 , pos = -1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(i - cur + 1 >= primes[mid]){
                        l = mid + 1;
                        pos = mid;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                ans.push_back({cur , cur + primes[pos] - 1});
                sswap(cur , cur + primes[pos] - 1);
                cur = cur + primes[pos] - 1;
            }
        }   
        else if(cur > i){
            while(cur - i + 1 > 1){
                int l = 0 , r = primes.size() - 1 , pos = -1;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(cur - i + 1 >= primes[mid]){
                        l = mid + 1;
                        pos = mid;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                sswap(cur , cur - primes[pos] + 1);
                ans.push_back({cur , cur - primes[pos] + 1});
                cur = cur - primes[pos] + 1;
            }
        }
    }
    cout << (int)ans.size() << endl;
    for(auto& e : ans){
        cout << min(e.x , e.y) << " " << max(e.y , e.x) << endl;
    }
}