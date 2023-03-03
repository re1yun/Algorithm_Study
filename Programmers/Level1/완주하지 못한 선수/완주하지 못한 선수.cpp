#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// compare names in participant and completion and return the name that is not in completion
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // sort names in participant and completion
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // compare names in participant and completion
    for (int i = 0; i < completion.size(); i++){
        if (participant[i] != completion[i]){
            answer = participant[i];
            return answer;
        }
    }
    // return the last name in participant
    answer = participant[participant.size() - 1];
    return answer;
}