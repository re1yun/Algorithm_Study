#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    // init
    vector<int> answer;
    int sIndex = 0, eIndex = 0;
    int ans1 = 0, ans2 = sequence.size();
    int sum = 0;
    
    // algorithm: starting from the beginning, check every possible combination
    // step 1: run until the end of the sequence
    while(eIndex <= sequence.size()){
        // step 2: add to sum
        while(sum < k){
            sum += sequence[eIndex++];
        }
        // step 3: if sum is k, check if answer has to be updated
        if(sum == k && eIndex - 1 - sIndex < ans2 - ans1){
            ans2 = eIndex - 1;
            ans1 = sIndex;
        }
        // step 4: remove first num and increase the index
        sum -= sequence[sIndex++];
    }
    // step 5: return answer
    answer.push_back(ans1);
    answer.push_back(ans2);
    
    return answer;
}