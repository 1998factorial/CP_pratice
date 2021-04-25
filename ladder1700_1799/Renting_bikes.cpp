#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N , M , A;

bool check(int mid , vector<ll>& b , vector<ll>& p){
    // check if the richest mid ppl can rent the 
    // cheapest mid bikes
    ll B = A;
    for(int i = 0; i < mid; ++i){
        if(b[i] >= p[mid - i - 1])continue;
        ll diff = p[mid - i - 1] - b[i];
        if(diff > B)return 0;
        B -= diff;
    }
    return B >= 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> A;
    vector<ll> b(N) , p(M);
    for(int i = 0; i < N; ++i)cin >> b[i];
    for(int i = 0; i < M; ++i)cin >> p[i];
    sort(b.begin() , b.end() , [&](auto& x , auto& y){
        return x > y;
    });
    sort(p.begin() , p.end());
    int l = 0 , r = min(N , M) , v1 = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid , b , p)){
            v1 = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << v1 << " ";
    if(v1 == 0){
        cout << 0 << endl;
        exit(0);
    }
    ll v2 = 0;
    vector<ll> bikes;
    for(int i = 0; i < v1; ++i)bikes.push_back(p[i]);
    reverse(bikes.begin() , bikes.end());
    // for the cheapest v1 bikes, check the minimal amount of pubilc
    // budget we need 
    vector<ll> min_need;
    for(int i = 0; i < v1; ++i){
        min_need.push_back(max(0ll , bikes[i] - b[i]));
    }
    vector<ll> sufix(min_need.size() + 1);
    for(int i = min_need.size() - 1; i >= 0; --i){
        sufix[i] = min_need[i];
        if(i < min_need.size() - 1)sufix[i] += sufix[i + 1];
    }
    ll B = A;
    for(int i = 0; i < min_need.size(); ++i){
        ll can = min(bikes[i] , B - sufix[i + 1]);
        ll need_to_pay = bikes[i] - can;
        v2 += need_to_pay;
        B -= can;
    }
    cout << v2 << endl;
}