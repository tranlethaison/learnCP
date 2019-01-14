// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
/*
dp(0) = 1
dp(1) = 1
dp(2) = 2
dp(n) = dp(n-1) + dp(n-2) + dp(n-3)
*/
#include <bits/stdc++.h>
using namespace std;

int waysToHops(int n){
    int T[n+1];

    T[0] = 1;
    T[1] = 1;
    T[2] = 2;
    for(int i=3; i<n+1; i++)
        T[i] = T[i-1] + T[i-2] + T[i-3];

    return T[n];
}

int main(){
    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        printf("%d\n", waysToHops(n));
    }
    return 0;
}