#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    for(int i = 100000000; i > 0; i /= 10){
        answer += (n / i);
        n %= i;
    }
    return answer;
}