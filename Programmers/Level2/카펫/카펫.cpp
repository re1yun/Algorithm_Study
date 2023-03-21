/**
 * @file 카펫.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return size of carpet
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <vector>

using namespace std;

// get pair of divisors of yellow
vector<pair<int, int>> divisors(int n){
    vector<pair<int, int>> divs;
    for(int i = 1; i * i <= n; i++){
        if(n%i == 0){
            divs.push_back({i, n/i});
        }
    }
    return divs;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> yellows = divisors(yellow);
    // iterate through possible divisors to check if it matches given number of tiles(brown * yellow)
    for(auto y : yellows){
        if((y.first+2)*(y.second+2) == brown+yellow){
            answer.push_back(y.second+2);
            answer.push_back(y.first+2);
            return answer;
        }
    }
}