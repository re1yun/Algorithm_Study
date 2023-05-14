#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int N;  cin >> N;
    int dp[105][10] ={0,};

    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                dp[i][j] = dp[i - 1][1];
            }else if(j == 9){
                dp[i][j] = dp[i - 1][8];
            }else{
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    long long fin = 0;
    for(int i = 1; i < 10; i++){
        fin = (fin + dp[N][i]) % 1000000000;
    }
    cout << fin % 1000000000<< "\n";
    return 0;
}