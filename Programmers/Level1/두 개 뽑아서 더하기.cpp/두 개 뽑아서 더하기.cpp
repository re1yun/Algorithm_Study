#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return all unique numbers that can be added from different index of numbers
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    // double for loop to get all possible addition of numbers
    for(int i = 0; i < numbers.size() - 1; i++){
        for(int j = i + 1; j < numbers.size(); j++){
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    // get unique values in sorted manner
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}