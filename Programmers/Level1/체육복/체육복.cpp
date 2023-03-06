#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return total number of students who can participate in gym class
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    // students who lost their gym cloth and have reserve, can only wear their reserves
    for(int i = 0; i < lost.size(); i++){
        if(find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()){
            reserve.erase(find(reserve.begin(), reserve.end(), lost[i]));
            lost.erase(find(lost.begin(), lost.end(), lost[i]));
            answer++;
            i--;
        }
    }
    // students who lost their gym cloth and don't have reserve, can borrow from their neighbors
    for(int num : lost){
        if(find(reserve.begin(), reserve.end(), num - 1) != reserve.end()){
            reserve.erase(find(reserve.begin(), reserve.end(), num - 1));
            answer++;
        }
        else if(find(reserve.begin(), reserve.end(), num + 1) != reserve.end()){
            reserve.erase(find(reserve.begin(), reserve.end(), num + 1));
            answer++;
        }
    }
    return answer;
}