/**
 * @file 멀리 뛰기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief Programmers Level2 멀리 뛰기
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long dp[2001] = {0, };
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    return dp[n];
}