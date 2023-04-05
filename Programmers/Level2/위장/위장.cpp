/**
 * @file 위장.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> combination;
    for(vector<string> cloth : clothes){
        combination[cloth[1]]++;
    }
    for(auto it = combination.begin(); it != combination.end(); it++){
        answer *= (it->second + 1);
    }  
    answer--;
    return answer;
}