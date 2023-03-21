/**
 * @file 짝지어 제거하기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief check if s can be reduced to an empty string by removing pairs of adjacent letters
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <stack>

using namespace std;

// return availability of s reduced to an empty string by removing pairs of adjacent letters
int solution(string s) {
    int answer = -1;
    // letters: to store letters
    stack<char> letters;

    for(char letter : s){
        if(!letters.empty() && letters.top() == letter)
            letters.pop();
        else
            letters.push(letter);
    }

    if(!letters.empty())
        answer = 0;
    else
        answer = 1;
    return answer;
}