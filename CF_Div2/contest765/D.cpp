#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cout << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int N,K,a[300005],Kh=-1;
vector<int>group[31];
vector<int>bt[300005];
int pt[300005],tr[300005*31][2],cnt;
void add(int val){
    int now=1;
    for(int bit=29;bit>=0;--bit){
        int v=val>>bit&1;
        if(tr[now][v]==0){
            tr[now][v]=++cnt;
        }
        now=tr[now][v];
    }
}
void del(int rt){
    if(tr[rt][0]){
        del(tr[rt][0]);
        tr[rt][0]=0;
    }
    if(tr[rt][1]){
        del(tr[rt][1]);
        tr[rt][1]=0;
    }
}
int query(int val){
    int now=1,ans=0;
    for(int bit=29;bit>=0;--bit){
        int v=val>>bit&1;
        if(tr[now][v^1]){
            ans|=(1<<bit);
            now=tr[now][v^1];
        }
        else{
            now=tr[now][v];
        }
    }
    return ans;
}
vector<int>solve(vector<int>vec){
    if(vec.size()<=1){
        return vec;
    }
    vector<int>gp[35],zero;
    // distribute by highest bit by now
    for(int i:vec){
        if(pt[i]>=0){
            if(bt[i][pt[i]]>Kh){
                gp[bt[i][pt[i]]].push_back(i);
                pt[i]--;
            }
            else{
                zero.push_back(i);
                pt[i]--;
            }
        }
    }
    vector<int>ans;
    for(int j=29;j>Kh;--j){
        vector<int>tmp=solve(gp[j]);
        for(int x:tmp){
            ans.push_back(x);
        }
    }
    // find among zero, if we have x,y , x^y>=K, we need at most 2
    int p=-1,q=-1;
    cnt=1;
    for(int i:zero){
        if(query(a[i])>=K){
            p=i;
        }
        add(a[i]);
    }
    del(1);
    if(~p){
        for(int i:zero){
            if(i!=p&&(a[i]^a[p])>=K){
                q=i;
                break;
            }
        }
        ans.push_back(p);
        ans.push_back(q);
    }
    else{
        if(zero.size())ans.push_back(zero.back());
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=1;i<=N;++i){
        cin>>a[i];
        int high=-1;
        bt[i].push_back(-1);
        for(int j=0;j<=29;++j){
            if(a[i]>>j&1){
                bt[i].push_back(j);
            }
        }
    }
    if(K==0){
        cout<<N<<endl;
        for(int i=1;i<=N;++i)cout<<i<<" ";
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=N;++i)pt[i]=bt[i].size()-1;
    Kh=-1;
    for(int j=29;j>=0;--j)if(K>>j&1){
        Kh=j;
        break;
    }
    vector<int>id(N);
    for(int i=1;i<=N;++i)id[i-1]=i;
    vector<int>ans=solve(id);
    if(ans.size()<=1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<(int)ans.size()<<endl;
    for(int i:ans)cout<<i<<" ";
    cout<<endl;
}   