/**
 * @file 땅따먹기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief Programmers Level2 땅따먹기
 * @version 0.1
 * @date 2023-05-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
    // init
    int answer = 0;
    int dp[4] = {0, };
    int ndp[4] = {0, };
    // algorithm
    // on every row,
    for(int i = 0; i < land.size(); i++){
        // get ndp value
        for(int j = 0; j < 4; j++){
            int max = 0;
            // based on max dp value
            for(int k = 0; k < 4; k++){
                if(j == k)
                    continue;
                if(dp[k] > max){
                    max = dp[k];
                }
            }
            ndp[j] = land[i][j] + max;
        }
        // get dp
        for(int j = 0; j < 4; j++){
            dp[j] = ndp[j];
        }
    }
    for(int i = 0; i < 4; i++){
        if(answer < dp[i])
            answer = dp[i];
    }
    return answer;
}