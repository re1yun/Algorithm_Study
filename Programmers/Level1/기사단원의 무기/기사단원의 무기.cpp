#include <string>
#include <vector>

using namespace std;

// return the number of divisors of number, but faster than O(n)
int get_divisor(int number){
    int cnt = 0;
    // iterate through numbers from 1 to sqrt(number)
    for(int i = 1; i * i <= number; i++){
        // if number is divisible by i, increase cnt by 1
        if(number % i == 0){
            cnt += 1;
            // if i is not sqrt(number), increase cnt by 1
            if(i * i != number) cnt += 1;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    // iterate through numbers from 1 to number
    for(int i = 1; i <= number; i++){
        int cnt = get_divisor(i);
        // if cnt is bigger than limit, add power to answer
        if(cnt > limit) answer += power;
        // else, add cnt to answer
        else answer += cnt;
    }
    return answer;
}