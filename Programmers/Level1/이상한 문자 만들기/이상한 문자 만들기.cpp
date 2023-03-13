#include <string>
#include <vector>

using namespace std;

// return combination of upper and lowercase letters of s 
string solution(string s) {
    string answer = "";
    // iterate through s, if blank comes up, reset the index
    bool index = true;
    for(int i = 0; i < s.size(); i++){
        // if s[i] is blank, new word starts
        if(s[i] == ' '){
            index = true;
            answer += s[i];
        }
        // if s[i] is even index(true) and lower case, change to upper case letter
        else if(s[i] >= 'a' && s[i] <= 'z' && index == true){
            answer += toupper(s[i]);
            index = false;
        }
        // if s[i] is odd index(false) and upper case, change to lower case letter
        else if(s[i] >= 'A' && s[i] <= 'Z' && index == false){
            answer += tolower(s[i]);
            index = true;
        }
        // else, put s[i] to answer and change index
        else{
            answer += s[i];
            index = (index == true) ? false : true;
        }   
    }
    return answer;
}