#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    // init
    vector<int> answer(2, 0);
    set<string> gem_types(gems.begin(), gems.end());
    unordered_map<string, int> gem_counts;
    int head = 0, end = 0;
    answer[1] = 100001;
    
    // algorithm
    // step 1. check each gem type
    while(end < gems.size()){
        gem_counts[gems[end++]]++;
        
        // step 2. if all gem types are included, move head pointer to contain minimum gems
        while (gem_counts.size() == gem_types.size() || gem_counts[gems[head]] > 1) {
            if(gem_counts[gems[head]] > 1) {
                gem_counts[gems[head++]]--;
            }
            else {
                break;
            }
        }

        // step 3. if all gem types are included and the length is shorter than the previous one, update answer
        if (gem_counts.size() == gem_types.size() && end - head < answer[1] - answer[0] + 1) {
            answer = {head + 1, end};
        }
    }
    
    return answer;
}