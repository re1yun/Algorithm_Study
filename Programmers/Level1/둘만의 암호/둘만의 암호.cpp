#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(char c : s){
        for(int i = 0; i < index; i++){
            c = (char)((c + 1) > 122 ? 'a' : c + 1);
            // if skip string does not contain c, then continue, else i -= 1
            if(skip.find(c) == string::npos){
                continue;
            }
            else{
                i -= 1;
            }
        }
        answer += c;
    }
    return answer;
}