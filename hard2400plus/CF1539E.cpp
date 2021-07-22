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
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 1e9 + 7;
/*
    insight: each card can work for some range of time
    intuition: we want to make choices such that each card can 
    last for as long as possible
*/
int N , M , K[maxn] , logs[maxn];
int take[maxn][2]; 
// take[i][0] = if the ith card is taken by left hand, for how long can we not take any other cards on left hand?
// take[i][1] = if the ith card is taken by right hand, for how long can we not take any other cards on right hand?
int other[maxn][2];
// other[i][0] = if the ith card is taken by left hand, for how long can we not take any other cards on right hand?
// other[i][1] = if the ith card is taken by right hand, for how long can we not take any other cards on left hand?
int pre[maxn][2];
pii L[maxn] , R[maxn] , table_l[25][maxn] , table_r[25][maxn];
pii merge(pii l , pii r){
    if(l.x == -1 || l.y == -1)return {-1 , -1};
    if(r.x == -1 || r.y == -1)return {-1 , -1};
    pii ans = make_pair(max(l.x , r.x) , min(l.y , r.y));
    if(ans.x > ans.y)return {-1 , -1};
    return ans;
}
pii query_l(int l, int r) {
    if(l > r)return {-1 , -1};
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return merge(table_l[logs[len]][l] , table_l[logs[len]][pos]);
}
pii query_r(int l, int r) {
    if(l > r)return {-1 , -1};
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return merge(table_r[logs[len]][l] , table_r[logs[len]][pos]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> K[i];
        cin >> L[i].x >> L[i].y;
        cin >> R[i].x >> R[i].y;
    }
    for(int i = 2; i < maxn; ++i){
        logs[i] = logs[i / 2] + 1;
    }
    for(int i = 1; i <= N; ++i){
        table_l[0][i] = L[i];
        table_r[0][i] = R[i];
    }
    for(int i = 1; i <= logs[N]; ++i){
        int prel = (1 << (i - 1));
        for(int j = 1; j <= N; ++j){
            if(j + prel <= N){
                table_l[i][j] = merge(table_l[i - 1][j] , table_l[i - 1][j + prel]);
                table_r[i][j] = merge(table_r[i - 1][j] , table_r[i - 1][j + prel]);
            }
            else{
                table_l[i][j] = table_l[i - 1][j];
                table_r[i][j] = table_r[i - 1][j];
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        take[i][0] = -1;
        int l = i , r = N;
        while(l <= r){
            int mid = (l + r) / 2;
            pii interval = query_l(i , mid);
            if(interval.x <= K[i] && K[i] <= interval.y){
                take[i][0] = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        take[i][1] = -1;
        l = i , r = N;
        while(l <= r){
            int mid = (l + r) / 2;
            pii interval = query_r(i , mid);
            if(interval.x <= K[i] && K[i] <= interval.y){
                take[i][1] = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        //for(int j : {0 , 1})printf("take[%d][%d] = %d\n" , i , j , take[i][j]);
    }
    pii interval = make_pair(0 , inf32);
    for(int i = 1; i <= N; ++i){
        interval = merge(interval , R[i]);
        if(interval.x <= 0 && 0 <= interval.y){
            other[1][0] = i;
        }
        else{
            break;
        }
    }
    interval = make_pair(0 , inf32);
    for(int i = 1; i <= N; ++i){
        interval = merge(interval , L[i]);
        if(interval.x <= 0 && 0 <= interval.y){
            other[1][1] = i;
        }
        else{
            break;
        }
    }
    for(int i = 2; i <= N; ++i){
        for(int cur_hand = 0; cur_hand < 2; ++cur_hand){
            for(int pre_hand = 0; pre_hand < 2; ++pre_hand){
                int take_dis = take[i - 1][pre_hand];
                int other_dis = other[i - 1][pre_hand];
                if(min(take_dis , other_dis) < i - 1)continue;
                if(cur_hand == pre_hand){
                    // do not change hand
                    if(other_dis >= other[i][cur_hand]){
                        other[i][cur_hand] = other_dis;
                        pre[i][cur_hand] = pre_hand;
                    }
                }
                else{
                    // change hand
                    if(take_dis >= other[i][cur_hand]){
                        other[i][cur_hand] = take_dis;
                        pre[i][cur_hand] = pre_hand;
                    }
                }
            }
        }
    }
    for(int hand = 0; hand < 2; ++hand){
        if(min(take[N][hand] , other[N][hand]) >= N){
            cout << "Yes" << endl;
            vector<int> path;
            int cur_hand = hand;
            for(int i = N; i >= 1; --i){
                path.push_back(cur_hand);
                cur_hand = pre[i][cur_hand];
            }
            reverse(path.begin() , path.end());
            for(int i : path)cout << i << " ";
            cout << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}