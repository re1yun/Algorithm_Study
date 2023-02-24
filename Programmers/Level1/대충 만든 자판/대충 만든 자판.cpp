#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    // find the longest string in the vector
    auto maxStr = max_element(keymap.begin(), keymap.end(), 
                    [](const string& a, const string& b) {
                        return a.length() < b.length();
                    });
    int maxLen = maxStr->length();
    
    // targets의 각 문자열을 순회하며 keymap의 각 문자열을 순회하며 비교
    for(string str : targets){
        int sum = 0;
        bool check = true;
        // str의 각 문자를 순회하며 keymap의 각 문자열을 순회하며 비교
        for(int i = 0; i < str.length(); i++){
            check = true;
            int cnt = 0;
            // keymap의 각 문자열을 순회하며 비교
            while(check){
                for(string str1 : keymap){
                    if(str[i] == str1[cnt]){
                        sum += (cnt + 1);
                        check = false;
                        break;
                    }
                    // str1의 문자열이 없을 때
                    if(!str1[cnt]){
                        continue;
                    }
                }
                cnt++;
                // cnt가 keymap의 문자열 중 가장 긴 문자열의 길이보다 커지면 break
                if(cnt > maxLen){
                    break;
                }
            }
        }
        // check가 true이면 맞는 문자가 없으므로 -1을 push
        if(check){
            sum = -1;
        }
        answer.push_back(sum);
    }
    return answer;
}
