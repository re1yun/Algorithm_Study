/**
 * @file 파일명 정렬.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> files) {
    // init
    vector<string> answer;
    vector<pair<string, pair<string, int>>> dict;
    unordered_map<string, int> index;
    
    // algorithm
    // create dict
    int cnt = 0;
    for(string file : files){
        index[file] = cnt++;
        string head = "", number = "";
        int index = 0;
        while(file[index] < '0' || file[index] > '9'){
            head += tolower(file[index++]);
        }
        while(file[index] >= '0' && file[index] <= '9' && number.size() <= 5){
            number += file[index++];
        }
        dict.push_back(make_pair(file, make_pair(head, stoi(number))));
    }
    
    // sort
    sort(dict.begin(), dict.end(), [&index](auto a, auto b){
        if(a.second.first != b.second.first)
            return a.second.first < b.second.first;
        else if(a.second.second != b.second.second)
            return a.second.second < b.second.second;
        else
            return index[a.first] < index[b.first];
    });
    
    for(int i = 0; i < dict.size(); i++){
        answer.push_back(dict[i].first);
    }
    
    return answer;
}