/**
 * @file 할인 행사.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wantMap, curMap;
    for(int i = 0; i < want.size(); i++){
        wantMap.insert(make_pair(want[i], number[i]));
    }
    int totalProduct = 0;
    for(int i = 0; i < discount.size(); i++){
        // for the first ten products, just add to curMap
        if(totalProduct != 10){
            if(curMap.find(discount[i]) == curMap.end()){
                curMap.insert(make_pair(discount[i], 1));
                totalProduct++;
            }
            else{
                curMap[discount[i]]++;
                totalProduct++;
            }
        }
        // now if we have total ten products, check if it is same as wantMap
        else{
            if(curMap == wantMap)
                answer++;
            // if not, remove the first product and add the new product
            
            curMap[discount[i - 10]]--;
            if(curMap[discount[i - 10]] == 0)
                curMap.erase(discount[i - 10]);
            if(curMap.find(discount[i]) == curMap.end()){
                curMap.insert(make_pair(discount[i], 1));
            }
            else{
                curMap[discount[i]]++;
            }
            
        }
    }
    if(curMap == wantMap)
        answer++;
    return answer;
}