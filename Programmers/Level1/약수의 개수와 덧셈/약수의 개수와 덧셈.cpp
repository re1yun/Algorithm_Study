#include <string>
#include <vector>

using namespace std;

// return sum of numbers with even dividers and sub of numbers with odd dividers
int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++){
        int cnt = 0;
        for(int j = 1; j * j <= i; j++){
            if(j * j == i)  cnt++;
            else if(i % j == 0) cnt += 2;
        }
        if(cnt % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}