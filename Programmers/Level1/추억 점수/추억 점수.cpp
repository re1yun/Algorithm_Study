/**
 * @file 추억 점수.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> dict;
    for(int i = 0; i < name.size(); i++){
        dict[name[i]] = yearning[i];
    }
    for(int i = 0; i < photo.size(); i++){
        int score = 0;
        for(int j = 0; j < photo[i].size(); j++){
            score += dict[photo[i][j]];
        }
        answer.push_back(score);
    }
    return answer;
}