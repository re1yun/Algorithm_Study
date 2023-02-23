#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    for(char c : s){
        answer.push_back(c - '0');
    }
    reverse(answer.begin(), answer.end());
    return answer;
}