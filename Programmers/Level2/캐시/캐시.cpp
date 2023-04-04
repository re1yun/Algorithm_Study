/**
 * @file 캐시.cpp
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
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> q;
    if(cacheSize == 0) return cities.size() * 5;
    for(int i = 0; i < cities.size(); i++){
        string city = cities[i];
        for(int j = 0; j < city.size(); j++){
            city[j] = tolower(city[j]);
        }
        if(q.size() < cacheSize){
            if(find(q.begin(), q.end(), city) == q.end()){
                q.push_back(city);
                answer += 5;
            }
            else{
                q.erase(find(q.begin(), q.end(), city));
                q.push_back(city);
                answer += 1;
            }
        }
        else{
            if(find(q.begin(), q.end(), city) == q.end()){
                q.pop_front();
                q.push_back(city);
                answer += 5;
            }
            else{
                q.erase(find(q.begin(), q.end(), city));
                q.push_back(city);
                answer += 1;
            }
        }
    }
    return answer;
}