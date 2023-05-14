#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    int N;          cin >> N;
    int dp[303] = {0,};
    int score[303] = {0,};
    for(int i = 1; i <= N; i++){
        cin >> score[i];
    }
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    if(score[1] + score[3] > score[2] + score[3])
        dp[3] = score[1] + score[3];
    else
        dp[3] = score[2] + score[3];
    for(int i = 4; i <= N; i++){
        if(dp[i - 2] + score[i] > dp[i - 3] + score[i - 1] + score[i])
            dp[i] = dp[i - 2] + score[i];
        else
            dp[i] = dp[i - 3] + score[i - 1] + score[i];
    }
    cout << dp[N];
    return 0;
}