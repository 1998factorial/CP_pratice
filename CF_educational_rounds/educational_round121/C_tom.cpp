#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll x) {
    return x*(x+1)/2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>K(n+1),H(n+1),c(n+1);
        for(int i=1;i<=n;i++)cin>>K[i];
        for(int i=1;i<=n;i++)cin>>H[i];
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                H[j]=max(H[j],H[i]-(K[i]-K[j]));
            }
        }
        ll mana=0;
        for(int i=2;i<=n;i++){
            int d=K[i]-K[i-1];
            c[i]=(d>=H[i]);
        }
        ll power=H[1];
        ll at=K[1];
        for (int i=2;i<=n;i++) {
            if(c[i]){
                mana+=cal(power);
                power=H[i];
            }
            else{
                power+=(K[i]-K[i-1]);
            }
        }
        if(power){
            mana+=cal(power);
        }
        cout<<mana<<endl;
    }
}