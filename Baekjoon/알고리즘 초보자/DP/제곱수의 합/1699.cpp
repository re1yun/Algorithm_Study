#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int N;      cin >> N;
    int dp[100001] = {0,};
    for(int i = 1; i <= N; i++){
        dp[i] = i;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 2; j * j <= i; j++){
            if(dp[i] > dp[i - j * j] + 1){
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }
    cout << dp[N];
    return 0;
}