/**
 * @file 괄호 회전하기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return number of correct bracket strings
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    // repeat the process s.size() times
    for(int i = 0; i < s.size(); i++){
        // first check if s is correctly bracketed string
        stack<char> bracket;
        bool check = true;
        for(char ch : s){
            if(ch == '{' || ch == '[' || ch == '('){
                bracket.push(ch);
            }
            else{
                if(bracket.empty()){
                    check = false;
                    break;
                }
                if(ch == '}' && bracket.top() == '{'){
                    bracket.pop();
                }
                else if(ch == ']' && bracket.top() == '['){
                    bracket.pop();
                }
                else if(ch == ')' && bracket.top() == '('){
                    bracket.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check && bracket.empty()){
            answer++;
        }
        // second rotate s
        s = s.substr(1) + s[0];
    }
    return answer;
}