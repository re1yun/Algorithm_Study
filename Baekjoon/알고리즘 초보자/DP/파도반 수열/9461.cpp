/*
점화식
dp[i] = dp[i - 1] + dp[i - 5]
그러므로 dp[5]까지 미리 선언해줘야함
*/
#include <iostream>

using namespace std;

int main(){
    int T;      cin >> T;
    long long dp[101] = {0,};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i = 6; i < 101; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    for(int i = 0; i < T; i++){
        int N;      cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}