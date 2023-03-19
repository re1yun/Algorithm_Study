#include <string>
#include <vector>

using namespace std;

// return number of Collatz solution applied to make given num a 1
int solution(int num) {
    int answer = 0;
    // if num is 1, return 0
    if(num == 1)
        return 0;
    // n: num
    long long n = num;
    // else, count Collatz solution applied
    while(n != 1 && answer <= 500){
        if(n % 2 == 0)
            n /= 2;
        else{
            n = 3 * n + 1;
        }
        answer++;
    }
    if(answer > 500)
        return -1;
    return answer;
}