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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    scanf("%d" , &t);
    while(t--){
        int N , M;
        scanf("%d %d" , &N , &M);
        vector<vector<int>> a(N + 1 , vector<int> (M + 1));
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                scanf("%d" , &a[i][j]);
            }
        }
        vector<vector<int>> maxL(N + 5 , vector<int> (M + 5 , -inf32));
        vector<vector<int>> minL(N + 5 , vector<int> (M + 5 , inf32));
        vector<vector<int>> maxR(N + 5 , vector<int> (M + 5 , -inf32));
        vector<vector<int>> minR(N + 5 , vector<int> (M + 5 , inf32));
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                maxL[i][j] = max(maxL[i][j - 1] , a[i][j]);
                minL[i][j] = min(minL[i][j - 1] , a[i][j]);
            }
            for(int j = M; j >= 1; --j){
                maxR[i][j] = max(maxR[i][j + 1] , a[i][j]);
                minR[i][j] = min(minR[i][j + 1] , a[i][j]);
            }
        }
        int best_cut = -1;
        vector<int> Rset;
        for(int cut = 1; cut < M; ++cut){
            vector<int> id(N);
            for(int i = 1; i <= N; ++i)id[i - 1] = i;
            sort(id.begin() , id.end() , [&](auto& l , auto& r){
                return minL[l][cut] > minL[r][cut];
            });
            multiset<int> Lmin[2] , Rmin[2] , Lmax[2] , Rmax[2];
            auto add = [&](int i , int j , int k) -> void {
                if(k)Lmin[k].insert(minL[i][j]);
                if(!k)Lmax[k].insert(maxL[i][j]);
                if(!k)Rmin[k].insert(minR[i][j + 1]);
                if(k)Rmax[k].insert(maxR[i][j + 1]);
            };
            auto del = [&](int i , int j , int k) -> void {
                if(k)Lmin[k].erase(Lmin[k].find(minL[i][j]));
                if(!k)Lmax[k].erase(Lmax[k].find(maxL[i][j]));
                if(!k)Rmin[k].erase(Rmin[k].find(minR[i][j + 1]));
                if(k)Rmax[k].erase(Rmax[k].find(maxR[i][j + 1]));
            };
            for(int i = 1; i <= N; ++i){
                add(i , cut , 0);
            }
            vector<int> select;
            for(int i = 0; i + 1 < N; ++i){
                int x = id[i];
                select.push_back(x);
                add(x , cut , 1);
                del(x , cut , 0);
                if(
                    *Lmin[1].begin() > *Lmax[0].rbegin()
                    &&
                    *Rmin[0].begin() > *Rmax[1].rbegin()
                    ){
                    best_cut = cut;
                    Rset = select;
                }
            }
        }
        if(~best_cut){
            printf("YES\n");
            vector<bool> r(N + 1);
            for(int i : Rset)r[i] = true;
            for(int i = 1; i <= N; ++i){
                if(r[i])printf("R");
                else printf("B");
            }
            printf(" %d\n" , best_cut);
        }
        else{
            printf("NO\n");
        }
    }
}