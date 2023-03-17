#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return vector without smallest element removed
vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    sort(arr.begin(), arr.end());
    answer.erase(find(answer.begin(), answer.end(), arr[0]));
    if(answer.size() == 0)
        answer.push_back(-1);
    return answer;
}