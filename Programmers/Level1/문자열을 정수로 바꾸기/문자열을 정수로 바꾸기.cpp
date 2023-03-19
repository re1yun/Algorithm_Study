#include <string>
#include <vector>

using namespace std;

// return int value of s
int solution(string s) {
    int answer = 0;
    // check if it has sign at the front
    if(s[0] == '+')
        answer = stoi(s.substr(1));
    else if(s[0] == '-')
        answer = -1 * stoi(s.substr(1));
    // if not, just convert
    else
        answer = stoi(s);
    return answer;
}