#include <string>
#include <stack>

using namespace std;

// return true if s is nested brackets else false
bool solution(string s) {
    bool answer = true;
    stack<char> brackets;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            brackets.push(s[i]);
        else if(!brackets.empty() && brackets.top() == '(')
            brackets.pop();
        else{
            return false;
        }
    }
    if(!brackets.empty())
        answer = false;
    return answer;
}