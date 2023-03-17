#include <string>
#include <cctype>

using namespace std;

// return true only if s size is 4 or 6 and made of numbers
bool solution(string s) {
    bool answer = true;
    if(s.size() == 4 || s.size() == 6){
        for (char c : s) {
            if (!isdigit(c)) {
                answer = false;
                break;
            }
        }
    }
    else
        answer = false;
    return answer;
}