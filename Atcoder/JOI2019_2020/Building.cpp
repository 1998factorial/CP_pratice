//#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 5e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , A[maxn * 2] , B[maxn * 2] , fullA[maxn * 4] , fullB[maxn * 4] , nex[maxn * 4];
vector<int> g[maxn * 4];

int id(int pos , int rem){
    return rem * N + pos;
}

pii revid(int v){
    return make_pair(v % N , v / N);
}

void DFS(int v){
    pii cur = revid(v);
    int pos = cur.x , rem = cur.y;
    if(pos == N - 1){
        if(rem == 0)fullA[v] = 1;
        else fullB[v] = 1;
    }
    else{
        for(int nv : g[v]){
            DFS(nv);
            if(rem == 0)fullA[v] |= fullA[nv];
            else fullB[v] |= fullB[nv];
        }
    }
}

int solve(int v , int na , int nb){
    pii cur = revid(v);
    int pos = cur.x , rem = cur.y;
    //printf("pos = %d , rem = %d , na = %d , nb = %d\n" , pos , rem , na , nb);
    if(pos == N - 1){
        if(rem == 0)++na;
        else ++nb;
        if(na == nb)return (na == nb);
    }
    int ans = 0;
    for(int nv : g[v]){
        if(solve(nv , na + (rem == 0) , nb + (rem == 1))){
            nex[v] = nv;
            ans = 1;
            break;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    N *= 2;
    for(int i = 0; i < N; ++i)cin >> A[i];
    for(int i = 0; i < N; ++i)cin >> B[i];
    for(int i = 0; i < N - 1; ++i){
        if(A[i] < A[i + 1]){
            g[id(i , 0)].push_back(id(i + 1 , 0));
        }
        if(A[i] < B[i + 1]){
            g[id(i , 0)].push_back(id(i + 1 , 1));
        }
        if(B[i] < A[i + 1]){
            g[id(i , 1)].push_back(id(i + 1 , 0));
        }
        if(B[i] < B[i + 1]){
            g[id(i , 1)].push_back(id(i + 1 , 1));
        }
    }
    DFS(id(0 , 0));
    DFS(id(0 , 1));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 2; ++j){
            nex[id(i , j)] = -1;
        }
    }
    if(solve(id(0 , 0) , 0 , 0)){
        int v = id(0 , 0);
        vector<int> ans;
        for(;~v;){
            pii cur = revid(v);
            int pos = cur.x , rem = cur.y;
            ans.push_back(rem);
            v = nex[v];
        }
        for(int i : ans){
            if(i == 0)cout << "A";
            else cout << "B";
        }
        cout << endl;
        exit(0);
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 2; ++j){
            nex[id(i , j)] = -1;
        }
    }
    if(solve(id(0 , 1) , 0 , 0)){
        int v = id(0 , 1);
        vector<int> ans;
        for(;~v;){
            pii cur = revid(v);
            int pos = cur.x , rem = cur.y;
            ans.push_back(rem);
            v = nex[v];
        }
        for(int i : ans){
            if(i == 0)cout << "A";
            else cout << "B";
        }
        cout << endl;
        exit(0);
    }
    cout << -1 << endl;
}