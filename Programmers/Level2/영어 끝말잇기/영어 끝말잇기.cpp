/**
 * @file 영어 끝말잇기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return index and round of first elemint who broke the rule
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    // iterate through words
    for(int i = 1; i < words.size(); i++){
        // if first letter of word is not equal to previous word's last letter or word is already used,
        if(words[i-1][words[i-1].size()-1] != words[i][0] || find(words.begin(), words.begin()+i, words[i]) != words.begin()+i){
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
        }
    }
    // if no one broke the rule, return [0, 0]
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}