#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    // init
    vector<string> answer;
    unordered_map<string, string> users;
    vector<pair<string, string>> history;
    for(string rec : record){
        // user[0]: state, user[1]: id, user[2]: nickname
        vector<string> user;
        int start = 0, end = rec.find(' ');
        while(end != string::npos){
            string temp = rec.substr(start, end - start);
            user.push_back(temp);
            start = end + 1;
            end = rec.find(' ', start);
        }
        user.push_back(rec.substr(start));
        
        if(user[0] == "Enter"){
            users[user[1]] = user[2];
            history.push_back(make_pair(user[1], user[0]));
        }
        else if(user[0] == "Leave"){
            history.push_back(make_pair(user[1], user[0]));
        }
        else if(user[0] == "Change"){
            users[user[1]] = user[2];
        }
    }
    
    for(auto i = history.begin(); i != history.end(); i++){
        if(i->second == "Enter"){
            answer.push_back(users[i->first] + "님이 들어왔습니다.");
        }
        else{
            answer.push_back(users[i->first] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}