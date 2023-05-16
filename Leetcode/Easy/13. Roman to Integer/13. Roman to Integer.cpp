#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    int answer = 0;
    // define dictionary
    unordered_map<char, int> dict;
    dict['I'] = 1;    dict['V'] = 5;    dict['X'] = 10;   dict['L'] = 50;
    dict['C'] = 100;  dict['D'] = 500;  dict['M'] = 1000;
    
    // define necessary variables
    // stack: stack to hold if current char is I or X or C
    stack<char> c;

    // algorithm: we could use stack, but possibility is limited
    // no, we should use stack...because variation is too much for hard coding
    for(int i = 0; i < s.size(); i++){
        // if stack is not empty, check if current char is I or X or C
        if(!c.empty()){
            char temp = c.top();
            c.pop();
            if(temp == 'I' && (s[i] == 'V' || s[i] == 'X')){
                answer -= dict[temp];
            }
            else if(temp == 'X' && (s[i] == 'L' || s[i] == 'C')){
                answer -= dict[temp];
            }
            else if(temp == 'C' && (s[i] == 'D' || s[i] == 'M')){
                answer -= dict[temp];
            }
            else
                answer += dict[temp];;
        }
        // if current char is I or X or C, save and proceed
        if(s[i] == 'I' || s[i] == 'X' || s[i] == 'C'){
            c.push(s[i]);
        }
        // else add to answer
        else{
            answer += dict[s[i]];
        }
    }
    
    // if stack is not empty, add to answer
    if(!c.empty())
        answer += dict[c.top()];

    return answer;
}