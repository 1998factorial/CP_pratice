#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char a[maxn];
int N , cnt[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> (a + 1);
    N = strlen(a + 1);
    int last_hash = 0;
    vector<int> ans;
    for(int i = 1; i <= N; ++i)if(a[i] == '#')last_hash = i;
    for(int i = 1; i <= N; ++i){
        cnt[i] += cnt[i - 1];
        if(a[i] == '(')++cnt[i];
        if(a[i] == ')')--cnt[i];
        if(a[i] == '#')--cnt[i];
        if(cnt[i] < 0){
            cout << -1 << endl;
            exit(0);
        }
        if(a[i] == '#'){
            if(i < last_hash)ans.push_back(1);
        }
    }
    ans.push_back(cnt[N] + 1);
    int pos = 0;
    for(int i = 1; i <= N; ++i){
        cnt[i] = 0;
        cnt[i] += cnt[i - 1];
        if(a[i] == '(')++cnt[i];
        if(a[i] == ')')--cnt[i];
        if(a[i] == '#'){
            cnt[i] -= ans[pos];
            ++pos;
        }
        if(cnt[i] < 0){
            cout << -1 << endl;
            exit(0);
        }
    }
    if(cnt[N] > 0){
        cout << -1 << endl;
        exit(0);
    }
    for(int i : ans)cout << i << endl;
}