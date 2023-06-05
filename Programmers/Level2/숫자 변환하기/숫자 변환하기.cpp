#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int x, int y, int n) {
    // init
    int answer = 0;
    deque<int> q1;
    q1.push_back(x);
    int check[1000001] = {0,};
    // algorithm
    if(x == y)
        return 0;
    // bfs
    while(!q1.empty()){
        deque<int> q2;
        // repeat until q1 becomes empty
        while(!q1.empty()){
            int temp = q1.front();
            if(temp == y){
                break;
            }
            q1.pop_front();
            // if current number is already bigger than y, skip
            if(temp > y)
                continue;
            // if next number already has step or bigger, skip
            if(check[temp + n] == 0 && temp + n <= y){
                q2.push_back(temp + n);
                check[temp + n] = check[temp] + 1;
            }
            if(check[temp * 2] == 0 && temp * 2 <= y){
                q2.push_back(temp * 2);
                check[temp * 2] = check[temp] + 1;
            }
            if(check[temp * 3] == 0 && temp * 3 <= y){
                q2.push_back(temp * 3);
                check[temp * 3] = check[temp] + 1;
            }
        }
        // if while loop is broken while q1 is not empty, it means that y is found
        if(!q1.empty())
            break;
        // else, get q2 to q1 and repeat
        q1 = q2;
    }
    if(check[y] == 0)
        return -1;
    else
        return check[y];
    return answer;
}