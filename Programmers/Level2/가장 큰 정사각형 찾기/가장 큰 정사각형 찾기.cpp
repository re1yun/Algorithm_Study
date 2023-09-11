#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    // init
    int answer = 0;
    vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), 0));
    for(int i = 0; i < board.size(); i++){
        dp[i][0] = board[i][0];
        if(answer < dp[i][0]){
            answer = dp[i][0];
        }
    }
    for(int i = 0; i < board[0].size(); i++){
        dp[0][i] = board[0][i];
        if(answer < dp[0][i]){
            answer = dp[0][i];
        }
    }
    // algorithm: Approach as DP problem
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 1 && i != 0 && j != 0){
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if(answer < dp[i][j]){
                    answer = dp[i][j];
                }
            }
        }
    }
    
    return answer * answer;
}