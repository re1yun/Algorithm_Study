#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return possible highest and lowest possible lotto result
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int cnt = 0, unk = 0;
    for(int num : lottos){
        if(num == 0){
            unk++;
            continue;
        }
        if(find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            cnt++;
    }

    answer.push_back(7 - (cnt + unk) > 6 ? 6 : 7 - (cnt + unk));
    answer.push_back(7 - cnt > 6 ? 6 : 7 - cnt);
    return answer;
}