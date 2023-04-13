/**
 * @file 압축.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief apply LZW compression algorithm
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    // init dict with one character
    for(int i = 0; i < 26; i++){
        string s = "";
        s += 'A' + i;
        dict.insert(make_pair(s, i + 1));
    }

    int count = 27;
    for(int i = 0 ; i < msg.size();){
        string temp = ""; temp += msg[i];
        int ansTemp = 0;
        auto is_In = dict.find(temp);
        // if string is in dict,
        while(is_In != dict.end()){
            ansTemp = is_In->second;
            temp += msg[++i];
            is_In = dict.find(temp);
        }
        answer.push_back(ansTemp);
        dict.insert(make_pair(temp, count++));
    }

    return answer;
}