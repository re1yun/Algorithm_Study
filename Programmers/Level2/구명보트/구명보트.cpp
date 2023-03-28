/**
 * @file 구명보트.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());

    for(int i = 0, j = people.size() - 1; i <= j;){
        if(i >= j){
            answer++;
            break;
        }
        // if the heaviest person and the lightest person can be on a boat,
        if(people[i] + people[j] <= limit){
            // erase the heaviest person and the lightest person
            i++;
            j--;
            answer++;
        }
        // if the heaviest person and the lightest person cannot be on a boat,
        else{
            // erase the heaviest person
            i++;
            answer++;
        }
    }
    
    return answer;
}