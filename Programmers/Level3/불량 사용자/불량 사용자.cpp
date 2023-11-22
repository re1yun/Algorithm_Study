#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int answer = 0;
set<set<string>> banned_list;

bool cmpStr(string a, string b){
    // if size is different, they are not matching
    if(a.size() != b.size()){
        return false;
    }
    for(int i = 0; i < a.size(); i++){
        // if b[i] == '*', move over to next character
        if(b[i] == '*'){
            continue;
        }
        else{
            // if two character doesn't match, they are not matching
            if(a[i] != b[i]){
                return false;
            }
        }
    }
    // if all above requirements meet, return true
    return true;
}

void dfs(vector<string> user_id, vector<string> banned_id, int banned_id_index, set<string> list){
    // step 1. if list is full, check if it duplicates and if not, increase answer
    if(list.size() == banned_id.size()){
        auto temp = banned_list.insert(list);
        if(temp.second){
            answer++;
        }
        return;
    }
    
    // step 2. check user id
    for(int i = 0; i < user_id.size(); i++){
        // step 2-1. if the user_id is matching,
        if(cmpStr(user_id[i], banned_id[banned_id_index])){
            auto res = list.insert(user_id[i]);
            // step 2-1-1. if inserted, check next banned_id
            if(res.second){
                dfs(user_id, banned_id, banned_id_index + 1, list);
                list.erase(res.first);
            }
            // step 2-1-2. continue searching for next matching id
        }
        // step 2-2. if no match, continue
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // init
    set<string> list;
    
    // algorithm
    dfs(user_id, banned_id, 0, list);
    return answer;
}