#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    // init
    string answer = "";

    // algorithm: only using 3 numbers, thus this is 3bit
    // n % 3 == 1, add 1
    // n % 3 == 2, add 2
    // n % 3 == 0, add 4
    // step 1: until divided is bigger than 3,
    while(n > 3){
        // step 1-1: if remaining is 0, add 4 and decrease n by 1, because since 124 land does not use 0
        if(n % 3 == 0){
            answer += '4';
            n -= 1;
        }
        // step 1-2: if remaining is 1, add 1
        else if(n % 3 == 1){
            answer += '1';
        }
        // step 1-3: if remaning is 2, add 2
        else if(n % 3 == 2){
            answer += '2';
        }
        // step 1-4: devide n by 3
        n /= 3;
    }
    // step 2: add based on last divided number
    if(n == 1){
        answer += '1';
    }
    else if(n == 2){
        answer += '2';
    }
    else if(n == 3){
        answer += '4';
    }
    // step 3: reverse them
    reverse(answer.begin(), answer.end());
    
    return answer;
}