#include <string>
#include <vector>

using namespace std;

// return number of cola bottle received
int solution(int a, int b, int n) {
    int answer = 0;
    // curCan: number of cola bottle currently have
    int curCan = n;
    // loop if curCan is enough to change for new one
    while(curCan >= a){
        // turnCan: number of cola bottle to turn in
        int turnCan = (curCan / a) * a;
        // reciCan: number of cola bottle to receive
        int reciCan = turnCan / a * b;
        curCan = curCan - turnCan + reciCan;
        answer += reciCan;        
    }
    return answer;
}