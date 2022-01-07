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

int ask(int a , int b , int c){
    cout << "? " << a << " " << b << " " << c << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void answer(const vector<int>& bad_ones){
    cout << "! " << (int)bad_ones.size() << " ";
    for(int i : bad_ones)cout << i << " ";
    cout << endl;
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , v;
        cin >> N;
        vector<array<int , 3>> bad , good; // 0->bad , 1->good
        for(int i = 1; i <= N; i += 3){
            v = ask(i , i + 1 , i + 2);
            assert(v == 0 || v == 1);
            if(!v){
                bad.push_back({i , i + 1 , i + 2});
            }
            else{
                good.push_back({i , i + 1 , i + 2});
            }
        }
        // (0,0,1) (1,1,0) name as (1,2,3)(4,5,6)
        // query form: (1,2,3)(2,3,4)(3,4,5)(4,5,6)
        // res: 0,1,1,1
        // (0,1,0) (1,1,0)
        // res: 0,1,1,1
        // (0,1,0) (0,1,1)
        // res: 0,0,0,1
        auto b = bad.back();
        auto g = good.back();
        vector<int> vec;
        vec.push_back(0);
        v = ask(b[1] , b[2] , g[0]);
        assert(v == 0 || v == 1);
        vec.push_back(v);
        v = ask(b[2] , g[0] , g[1]);
        assert(v == 0 || v == 1);
        vec.push_back(v);
        vec.push_back(1);
        int i0 , i1;
        //(b[0],b[1],b[2])(g[0],g[1],g[2])
        if(vec[1] == 1){
            i0 = b[0];
            i1 = g[0];
        }
        else if(vec[2] == 1){
            i0 = b[1];
            i1 = g[1];
        }
        else if(vec[3] == 1){
            i0 = b[2];
            i1 = g[2];
        }
        //DEBUG(i0);
        //DEBUG(i1);
        // after N/3 + 2 queries, we know one index for both bad and good
        // we need to use at most 2*N/3 to find all bad ones;
        vector<int> ans;
        ans.push_back(i0);
        //answer(ans);
        //continue;
        // bad ones: (0,0,0) (0,0,1)
        for(auto& e : bad){
            do{
                int x = e[0] , y = e[1] , z = e[2];
                // query (i1 , x , y)
                if(i0 == x || i1 == x)continue;
                if(i0 == y || i1 == y)continue;
                v = ask(i1 , x , y);
                assert(v == 0 || v == 1);
                if(v == 0){
                    // {x , y} = {0 , 0}
                    if(i0 != x && i1 != x)ans.push_back(x);
                    if(i0 != y && i1 != y)ans.push_back(y);
                    if(z != i1 && z != i0){
                        v = ask(i1 , i0 , z);
                        assert(v == 0 || v == 1);
                        if(v == 0){
                            ans.push_back(z);
                        }
                    }
                }
                else{
                    // {x , y} = {1 , 0} 
                    v = ask(i0 , i1 , x);
                    assert(v == 0 || v == 1);
                    if(v == 0){
                        if(i0 != x && i1 != x)ans.push_back(x);
                    }
                    else{
                        if(i0 != y && i1 != y)ans.push_back(y);
                    } 
                    if(z != i1 && z != i0){
                        ans.push_back(z);
                    }
                }
                break;
            }while(next_permutation(e.begin() , e.end()));
        }

        // good ones: (1,1,1) (1,1,0)
        for(auto& e : good){
            do{
                int x = e[0] , y = e[1] , z = e[2];
                // query (i0 , x , y)
                if(i0 == x || i1 == x)continue;
                if(i0 == y || i1 == y)continue;
                v = ask(i0 , x , y);
                assert(v == 0 || v == 1);
                if(v == 1){
                    // {x , y} = {1 , 1}
                    if(z != i1 && z != i0){
                        v = ask(i1 , i0 , z);
                        assert(v == 0 || v == 1);
                        if(v == 0){
                            ans.push_back(z);
                        }
                    }
                }
                else{
                    // {x , y} = {1 , 0} 
                    if(i0 != x && i1 != x){
                        v = ask(i0 , i1 , x);
                        assert(v == 0 || v == 1);
                        if(v == 0){
                            if(i0 != x && i1 != x)ans.push_back(x);
                        }
                        else{
                            if(i0 != y && i1 != y)ans.push_back(y);
                        } 
                    }
                    else{
                        if(x == i1){
                            if(y != i0)ans.push_back(y);
                        }
                    }   
                }
                break;
            }while(next_permutation(e.begin() , e.end()));
        }
        answer(ans);
    }
}