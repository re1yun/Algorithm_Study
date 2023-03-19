#include <string>
#include <vector>
#include <sstream>

using namespace std;

// convert s into JadenCase
string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string str = "";
    // seperate s by space
    while(getline(ss, str, ' ')){
        // convert str[0] to uppercase only if it is lowercase letter
        if('a' <= str[0] && str[0] <= 'z')
            str[0] += ('A' - 'a');
        // convert rest of string if it is uppercase letter
        for(int i = 1; i < str.size(); i++){
            if('A' <= str[i] && str[i] <= 'Z')
                str[i] -= ('A' - 'a');
        }
        answer += str;
        answer += ' ';
    }
    // erase last space if last element of s is not space
    if(s[s.size() - 1] != ' ')
        answer.erase(answer.size() - 1);
    return answer;
}