/**
 * @file 덧칠하기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return smallest number of brushing required to paint sections
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int curSec = 0;

    // iterate section to see if it can be painted
    for(int sec : section){
        // if current sec is already painted, continue
        if(sec <= curSec)
            continue;
        // if current sec cannot be painted from it because of maximum length n, end iteration
        else if(sec >= n - m + 1){
                answer++;
                break;
        }
        // if current sec can be painted from it, paint it
        else {
            curSec = sec + m - 1;
            answer++;
        }
    }
    return answer;
}