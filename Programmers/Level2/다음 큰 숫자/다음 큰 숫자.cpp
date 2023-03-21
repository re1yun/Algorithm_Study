/**
 * @file 다음 큰 숫자.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief find next biggest number than n which has same number of 1 in binary
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

// remove 0s
string removeZeros(string s){
    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            temp += '1';
    }
    return temp;
}

// convert num into binary number
string convertIntoBinary(int num){
    string temp = "";
    while(num > 0){
        temp += (num % 2) + '0';
        num /= 2;
    }
    return temp;
}

// return next smallest number than n
int solution(int n) {
    int answer = 0;
    // convert n into binary number and remove 0s
    string temp = convertIntoBinary(n);
    temp = removeZeros(temp);
    // count number of 1s
    int ones = temp.size();
    // find next biggest number than n which has same number of 1s
    while(1){
        n++;
        temp = convertIntoBinary(n);
        temp = removeZeros(temp);
        if(temp.size() == ones){
            answer = n;
            break;
        }
    }

    return answer;
}

