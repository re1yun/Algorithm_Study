/**
 * @file k진수에서 소수 개수 구하기.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return number of prime numbers in k-base number
 * @version 0.1
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(long long n){
    if(n == 1)
        return false;
    for(long long i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    // convert n to k-base number
    string k_base = "";
    if(k == 10)
        k_base = to_string(n);
    else{
        while(n > 0){
            k_base += to_string(n % k);
            n /= k;
        }
        // reverse k_base
        reverse(k_base.begin(), k_base.end());
    }
    // count prime numbers
    string temp = "";
    for(char c : k_base){
        if(c != '0')
            temp += c;
        else{
            if(temp != ""){
                long long num = stoll(temp);
                if(is_prime(num))
                    answer++;
            }
            temp = "";
        }
    }
    if(temp != ""){
        long long num = stoll(temp);
        if(is_prime(num))
            answer++;
    }
    return answer;
}