/**
 * @file 튜플.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return tuple
 * @version 0.1
 * @date 2023-04-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    // split string
    vector<vector<int>> v;
    vector<int> vtemp;
    string temp;
    for(int i = 2; i < s.size(); i++){
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
            temp += s[i];
        }
        else if(s[i] == '}'){
            vtemp.push_back(stoi(temp));
            v.push_back(vtemp);
            vtemp.clear();
            temp = "";
            i += 2;
        }
        else {
            vtemp.push_back(stoi(temp));
            temp = "";
        }
    }
    
    // sort by length
    sort(v.begin(), v.end(), [](vector<int> a, vector<int> b){
        return a.size() < b.size();
    });
    // push to answer
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(find(answer.begin(), answer.end(), v[i][j]) == answer.end()){
                answer.push_back(v[i][j]);
                break;
            }
        }
    }

    return answer;
}