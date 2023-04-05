/**
 * @file 행렬의 곱셈.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief matrix multiplication
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    // transpose arr2
    vector<vector<int>> arr2T;
    for(int i = 0; i < arr2[0].size(); i++){
        vector<int> temp;
        for(int j = 0; j < arr2.size(); j++){
            temp.push_back(arr2[j][i]);
        }
        arr2T.push_back(temp);
    }

    // multiply
    for(int i = 0; i < arr1.size(); i++){
        vector<int> temp;
        for(int j = 0; j < arr2T.size(); j++){
            int sum = 0;
            for(int k = 0; k < arr1[0].size(); k++){
                sum += arr1[i][k] * arr2T[j][k];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}