#include <string>
#include <vector>

using namespace std;

// return sum of a til b
long long solution(int a, int b) {
    long long answer = 0;
    if(a != b){
        int min = (a > b) ? b : a;
        int max = (a < b) ? b : a;
        while(min != max)
            answer += min++;
        answer += max;
    }
    else
        answer = a;
    return answer;
}