/**
 * @file 숫자의 표현.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief count number of ways that sum of consecutive numbers are equal to n
 * @version 0.1
 * @date 2023-03-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

/**
 * @brief count number of ways that sum of consecutive numbers are equal to n
 * 
 * @param n 
 * @return int 
 */
int solution(int n) {
    int answer = 0;
    // if n is 1, there is only 1 possibility
    if(n == 1)
        return 1;
    // count odd divisors of n
    for(int i = 3; i < (n / 2) + 1; i += 2){
        if(n % i == 0)
            answer++;
    }
    // if n is odd number, two consecutive numbers are possible
    if(n % 2 == 1)
        answer++;
    // count the last possibility, n itself
    answer++;
    return answer;
}