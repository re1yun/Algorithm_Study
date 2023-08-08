#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    // init
    string answer = "";
    int index = 0;
    
    // algorithm: find the max int from the range and repeat the process
    for(int i = 0; i < number.size() - k; i++){
        char maxNum = number[index];
        int maxIndex = index;
        // step 1: find biggest number from given range
        for(int j = index; j <= k + i; j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxIndex = j;
            }
        }
        // step 2: move to next range, starting from the biggest number found
        index = maxIndex + 1;
        answer += maxNum;
    }
    
    return answer;
}