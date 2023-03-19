#include <string>

using namespace std;

// return if number of 'p' and 'y' is same
bool solution(string s)
{
    bool answer = true;
    int y = 0, p = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p' || s[i] == 'P')
            p++;
        else if(s[i] == 'y' || s[i] == 'Y')
            y++;
    }
    // if number of p and y is different, return false
    if(p != y)
        answer = false;
    // else return true
    return answer;
}