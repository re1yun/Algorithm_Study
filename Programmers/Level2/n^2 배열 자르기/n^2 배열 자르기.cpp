/**
 * @file n^2 배열 자르기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return 1d array from 2d array
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    // get index of left in 2d array
    long long row = left / n, col = left % n;
    // from left to right, find which number is bigger and push to answer
    while(row * n + col % n <= right){
        answer.push_back(max(row, col % n) + 1);
        col++;
        if(col % n == 0){
            row++;
            col = 0;
        }
    }

    return answer;
}