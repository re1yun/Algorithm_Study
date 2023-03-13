#include <string>
#include <vector>

using namespace std;

// convert alphabet by n
string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ')
            answer += ' ';
        else if(s[i] >= 'A' && s[i] <= 'Z')
            answer += (s[i] + n) > 'Z' ? s[i] + n - ('Z' - 'A') - 1: s[i] + n;
        else if(s[i] >= 'a' && s[i] <= 'z')
            answer += (s[i] + n) > 'z' ? s[i] + n - ('z' - 'a') - 1: s[i] + n;
    }
    return answer;
}