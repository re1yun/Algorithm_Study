/**
 * @file 피보나치 수.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief fibonacci number problem
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

/**
 * @brief return fibonacci number of n
 * 
 * @param n 
 * @return int 
 */
int solution(int n) {
    // fib: memoization fibonacci
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
    return fib[n];
}