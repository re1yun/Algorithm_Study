#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return sum of missing numbers ranged from 0 to 9
int solution(vector<int> numbers) {
    int answer = 0;
    // sort numbers first
    sort(numbers.begin(), numbers.end());
    for(int i = 0, cnt = 0; i < 10; i++){
        if(i != numbers[cnt])
            answer += i;
        else
            cnt++;
    }
    return answer;
}