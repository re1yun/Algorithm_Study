#include <iostream>

using namespace std;

int main(){
    int N;      cin >> N;
    int dp[31] = {0,};
    if(N % 2 != 0){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for(int i = 4; i <= N; i++){
        dp[i] = dp[i - 2] * dp[2];
        for(int j = i - 4; j >= 0; j = j - 2){
            dp[i] = dp[i] + (dp[j] * 2);
        }
    }
    cout << dp[N];
    return 0;
}