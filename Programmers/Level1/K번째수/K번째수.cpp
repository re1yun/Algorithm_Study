#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// substring of array that meets conditioon of commands
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // iterate through commands and get answers
    for(vector<int> com : commands){
        // arr: from i to j
        vector<int> arr;
        for(int i = com[0] - 1; i < com[1]; i++){
            arr.push_back(array[i]);
        }
        sort(arr.begin(), arr.end());
        answer.push_back(arr[com[2] - 1]);
    }
    return answer;
}