#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> dict;
    for(int i = 0; i < s.size(); i++){
        if(dict.find(s[i]) == dict.end()){
            answer.push_back(-1);
        }
        else{
            answer.push_back(i - dict[s[i]]);
        }
        dict[s[i]] = i;
    }
    return answer;
}