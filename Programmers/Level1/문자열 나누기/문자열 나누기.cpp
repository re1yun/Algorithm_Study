#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    // iterate through s and apply the rules
    while(s.length() != 0){
        char x = s[0];
        int xcnt = 0, nxcnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == x){
                xcnt++;
            }
            else{
                nxcnt++;
            }
            // if number of x and number of non x is equal, break
            if(xcnt == nxcnt){
                break;
            }
        }
        // erase the first xcnt + nxcnt characters
        s.erase(0, xcnt + nxcnt);
        answer++;
    }
    return answer;
}