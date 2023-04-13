/**
 * @file N진수 게임.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// convert given num to n bit.
string convertNum(int num, int n){
    if(num == 0)
        return "0";
    string temp = "";
    while(num != 0){
        int r = num % n;
        if(r >= 10)
            temp += 'A' + r - 10;
        else
            temp += '0' + r;
        num /= n;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

// n: 진법 t: how many numbers to return m: total players p: order
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    int num = 0;
    // get all numbers to be used in the game
    while(temp.size() <= t * m){
        temp += convertNum(num++, n);
    }
    // save into answer only what we need
    for(int i = 0; i < t; i++){
        answer += temp[(p - 1) + (m * i)];
    }
    return answer;
}