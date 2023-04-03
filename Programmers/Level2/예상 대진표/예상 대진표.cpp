/**
 * @file 예상 대진표.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return number of rounds for a and b to meet
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    // answer: round
    int answer = 1;
    // b is always bigger than a
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    // if a is odd number and b is a + 1, it is in the same group
    if(b == a + 1 && a % 2 == 1) return answer;
    
    while(true){
        // update a, b
        if(a % 2 == 1)
            a = (a + 1) / 2;
        else
            a /= 2;
        if(b % 2 == 1)
            b = (b + 1) / 2;
        else
            b /= 2;
        answer++;
        if(b == a + 1 && a % 2 == 1)
            break;
    }

    return answer;
}