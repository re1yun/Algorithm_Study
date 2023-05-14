#include <iostream>

using namespace std;

int compare(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    cin.tie(NULL);
    int n = 0;      cin >> n;
    int wine[10001] = {0,};
    int dp[10001] = {0,};
    for(int i = 1; i <= n; i++){
        cin >> wine[i];
    }
    dp[0] = wine[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for(int i = 3; i <= n; i++){
        dp[i] = compare(dp[i - 3] + wine[i - 1] + wine[i], compare(dp[i - 2] + wine[i], dp[i - 1]));
    }
    cout << dp[n];
    return 0;
}