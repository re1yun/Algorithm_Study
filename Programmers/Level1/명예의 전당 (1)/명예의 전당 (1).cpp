#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    // set should be descending order
    multiset<int, greater<int>> honor;
    for(int i = 0; i < score.size(); i++){
        honor.insert(score[i]);
        // if honor size is smaller than k, push back the last element
        if(honor.size() < k){
            answer.push_back(*honor.rbegin());
        }
        // else, push back the kth element
        else{
            auto it = honor.begin();
            advance(it, k - 1);
            answer.push_back(*it);
        }
    }
    return answer;
}