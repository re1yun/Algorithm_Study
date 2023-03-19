#include <string>
#include <vector>

using namespace std;

// return smalles divisor that leaves 1
int solution(int n) {
    int answer = 1;
    while(n % answer != 1){
        answer++;
    }
    return answer;
}