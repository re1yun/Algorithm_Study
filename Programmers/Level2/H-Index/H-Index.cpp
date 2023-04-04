/**
 * @file H-Index.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return H-index
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // sort citations in ascending order
    sort(citations.begin(), citations.end());
    // citations.size() - i: h-index
    for(int i = 0; i < citations.size(); i++){
        if(citations.size() - i <= citations[i]){
            return citations.size() - i;
        }
    }
    return answer;
}