/**
 * @file 2 x n 타일링.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // init
    int answer = 0;
    long long dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;

    // algorithm
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    answer = dp[n];
    return answer;
}