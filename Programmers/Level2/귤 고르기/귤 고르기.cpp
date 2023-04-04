/**
 * @file 귤 고르기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // count the number of each tangerine
    unordered_map<int, int> tang;
    for(int tan : tangerine){
        tang[tan]++;
    }
    // sort by the number of tangerine
    vector<int> v;
    for(auto it = tang.begin(); it != tang.end(); it++){
        v.push_back(it->second);
    }
    sort(v.begin(), v.end(), greater<int>());
    // pick the tangerine
    while(k - v[answer] > 0){
        k -= v[answer];
        answer++;
    }
    // return the number of tangerine
    return answer + 1;
}