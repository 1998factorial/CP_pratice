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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
	while(t--){
        ll N , A , B;
		cin >> N >> A >> B;
		bool ok = 0;
		ll p = 1;
		if(A == 1){
			ok = (N - 1) % B == 0;
		} 
        else{
		    for(;;){
				if(p > N)break;
				if(((N - p) % B) == 0){
					ok = 1;
					break;
				}
				p *= A;
			}
		}
		if(ok)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}