#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    int N = 1e5;
    printf("%d\n" , N);
    for(int i = 1; i <= N; ++i){
        printf("%d " , i);
        //printf("%d " , rand() % 1000000);
    }
    printf("\n");
    int t = N;
    printf("%d\n" , t);
}