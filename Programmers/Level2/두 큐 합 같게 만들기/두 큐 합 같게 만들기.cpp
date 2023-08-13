#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    // init
    int answer = 0;
    queue<long long> q1, q2;
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < queue1.size(); i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    // algorithm: compare sum1 and sum2 and process the sum
    while(sum1 != sum2){
        // step 1: if queue1 is smaller, add and remove queue2's first element from sum1 and sum2
        if(sum1 < sum2){
            sum1 += q2.front();
            sum2 -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        // step 1: if queue2 is smaller, add and remove queue1's first element from sum1 and sum2
        else{
            sum2 += q1.front();
            sum1 -= q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        answer++;
        // step 2: exit the while loop if checking status goes over about twice the size of both queues
        if(answer > queue1.size() * 3){
            answer = -1;
            break;
        }
    }
    
    return answer;
}