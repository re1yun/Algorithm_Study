#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> stones, int k) {
    // init
    int answer = 0;
    map<int, int, greater<int>> stones_list;
    
    // algorithm : find minimal number of k range in stones
    // step 1. find biggest number of first k numbers
    for(int i = 0; i < k; i++){
        stones_list[stones[i]]++;
    }
    answer = stones_list.begin()->first;
    
    // step 2. iterate over stones
    for(int i = k; i < stones.size(); i++){
        // step 2-1. remove previous kth stone from list. if value is 0, erase it
        stones_list[stones[i - k]]--;
        if(stones_list[stones[i - k]] == 0){
            stones_list.erase(stones[i - k]);
        }
        
        // step 2-2. add new kth stone to list.
        stones_list[stones[i]]++;

        // step 2-3. update answer if biggest number in kth range is smaller than current answer
        if(answer > stones_list.begin()->first){
            answer = stones_list.begin()->first;
        }
    }
    return answer;
}