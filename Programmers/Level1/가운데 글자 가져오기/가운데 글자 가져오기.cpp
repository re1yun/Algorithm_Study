#include <string>
#include <vector>

using namespace std;

// return element in the middle for odd sized, two elements for even sized s
string solution(string s) {
    string answer = "";
    if(s.size() % 2 == 0)
        answer += s[s.size() / 2 - 1];
    answer += s[s.size() / 2];
    return answer;
}