/**
 * @file 점프와 순간 이동.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return sum of addition to create n
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    while(n != 0){
        if(n % 2 == 0){
            n /= 2;
        }
        else{
            n--;
            ans++;
        }
    }

    return ans;
}