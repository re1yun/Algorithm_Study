#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    // init
    int answer = 0, order_index = 0;
    // cBelt: container belt, aBelt: alternative belt
    int cBelt = 1;
    stack<int> aBelt;
    
    // algorithm: check cBelt and if it does not match with order, push to aBelt
    while(true){
        // step 1: check if next box is in cBelt
        if(cBelt <= order[order_index]){
            // step 1-1: add to aBelt until next box is found
            while(cBelt < order[order_index]){
                aBelt.push(cBelt++);
            }
            // step 1-2: since cBelt is same as ordered box, change index and more
            answer++;
            order_index++;
            cBelt++;
        }
        // step 2: if next box doesn't exist in cBelt,
        else{
            // step 2-1: if last box on aBelt is next box,
            if(!aBelt.empty() && aBelt.top() == order[order_index]){
                order_index++;
                aBelt.pop();
                answer++;
            }
            // step 2-2: if last box on aBelt is not the next box,
            else{
                break;
            }
        }
    }
    return answer;
}