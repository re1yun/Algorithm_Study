#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    // find multiple of divisor
    for(int num : arr){
        if(num % divisor == 0)
            answer.push_back(num);
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    // sort answer in ascending order
    sort(answer.begin(), answer.end());
    return answer;
}