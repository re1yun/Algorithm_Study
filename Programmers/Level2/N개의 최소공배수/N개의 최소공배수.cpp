/**
 * @file N개의 최소공배수.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return Least Common Multiple of N numbers
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;
// gcd: greatest common divisor
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// lcm: least common multiple
int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;

    answer = arr[0];
    for(int i = 1; i < arr.size(); i++){
        answer = lcm(answer, arr[i]);
    }

    return answer;
}