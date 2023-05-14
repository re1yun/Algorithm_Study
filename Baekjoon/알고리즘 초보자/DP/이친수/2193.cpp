#include <iostream>

using namespace std;

int main(){
    int N;      cin >> N;
    long long dp[92] = {0,};
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N] << "\n";
    return 0;
}