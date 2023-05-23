/**
 * @file 주식가격.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    // init
    vector<int> answer;
    deque<int> price(prices.begin(), prices.end());
    
    // algorithm
    while(!price.empty()){
        int cnt = 0;
        int temp = price.front();
        price.pop_front();
        auto front = price.begin();
        // until find the price that is lower than temp
        while(temp <= *front){
            cnt++;
            front++;
        }
        // if it has not gone till the end, increase cnt by one
        if(front != price.end())
            cnt++;
        // if stock price has gone down immediately, increase cnt by one
        if(cnt == 0 && price.empty() == false)
            cnt++;
        answer.push_back(cnt);
    }
    
    return answer;
}