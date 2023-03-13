#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return total number of ds that sum is less or equal to budget
int solution(vector<int> d, int budget) {
    int answer = 0;
    // sort d in ascending order and get total number of ds that sum is smaller than budget
    sort(d.begin(), d.end());
    while(d[answer] <= budget && answer < d.size()){
        budget -= d[answer];
        answer++;
    }
    return answer;
}