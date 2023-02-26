#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int cnt1 = 0, cnt2 = 0;
    // iterate through goal to see if each card is in cards1 or cards2
    for(string word : goal){
        if(cnt1 < cards1.size() && word == cards1[cnt1]){
            cnt1++;
            continue;
        }
        else if(cnt2 < cards2.size() && word == cards2[cnt2]){
            cnt2++;
            continue;
        }
        else{
            answer = "No";
            break;
        }
    }
    if(answer == "No")
        return answer;
    else
        return "Yes";
}