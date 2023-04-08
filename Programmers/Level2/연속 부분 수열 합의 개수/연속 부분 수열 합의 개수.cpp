/**
 * @file 연속 부분 수열 합의 개수.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> sum;
    vector<int> sequence = elements;
    
    // total available sequence = n * (n - 1) + 1
    // first for loop: n * (n - 1)
    for(int i = 0; i < sequence.size(); i++){
        // second for loop: 
        for(int j = i + 1; j < elements.size() + i; j++){
            // first check if the sum is already in the vector
            sum.insert(sequence[i]);
            // add the next element to the sum
            sequence[i] += elements[j % elements.size()];
        }
    }
    sum.insert(sequence[0]);
    return sum.size();
}