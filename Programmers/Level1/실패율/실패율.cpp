#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail;
    int num = stages.size();
    for(int i = 1; i <= N; i++){
        int cnt = 0;
        for(int j = 0; j < stages.size(); j++){
            if(stages[j] == i)
                cnt++;
        }
        if(cnt == 0)
            fail.push_back(make_pair(0, i));
        else
            fail.push_back(make_pair((double)cnt / num, i));
        num -= cnt;
    }
    // sort fail in descending order of failure rate, but if rate is same, sort in ascending order of stage number
    sort(fail.begin(), fail.end(), [](pair<double, int> a, pair<double, int> b){
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    });
    for(int i = 0; i < fail.size(); i++)
        answer.push_back(fail[i].second);
    return answer;
}