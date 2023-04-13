/**
 * @file 더 맵게.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return number of mix until all elements in scoville is higher than k
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    if(scoville.size() <= 1)
        return -1;
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scovil;
    for(int scov : scoville)
        scovil.push(scov);
    int smallest = scovil.top(), smallest2;
    // smallest element is smaller than K: first requirement / scoville has at least two elements
    while(smallest < K && scovil.size() >= 2){
        scovil.pop();
        smallest2 = scovil.top();
        scovil.pop();
        smallest += (smallest2 * 2);
        scovil.push(smallest);
        smallest = scovil.top();
        ++answer;
    }
    if(smallest < K)
        return -1;
    return answer;
}