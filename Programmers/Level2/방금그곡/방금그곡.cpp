#include <string>
#include <vector>

using namespace std;

// return PlayTime
int getPlayTime(string begin, string end){
    int bTime = stoi(begin.substr(0, 2)) * 60 + stoi(begin.substr(3, 2));
    int eTime = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));
    return eTime - bTime;
}

// replace #
string replaceSharp(string s) {
    string result = "";
    for (int i = 0; i < s.size(); ++i) {
        if (i < s.size() - 1 && s[i + 1] == '#') {
            result.push_back(tolower(s[i]));
            ++i;
        } else {
            result.push_back(s[i]);
        }
    }
    return result;
}


string solution(string m, vector<string> musicinfos) {
    // init
    string answer = "";
    int answerTime = 0;
    
    // algorithm:
    for(string musicinfo : musicinfos){
        // step 1: divide musicinfos by ','
        vector<string> temp;
        auto pos = musicinfo.find(',');
        auto ori = 0;
        for(int i = 0; i < 3; i++){
            temp.push_back(musicinfo.substr(ori, pos - ori));
            ori = pos + 1;
            pos = musicinfo.find(',', ori);
        }
        temp.push_back(musicinfo.substr(ori, pos - ori));
        
        // step 2: create melody strings
        string melody = "";
        int totalPlayTime = getPlayTime(temp[0], temp[1]);
        string temp3_replaced = replaceSharp(temp[3]);
        int playTime = temp3_replaced.size();
        for(int i = 0; i < totalPlayTime / playTime; i++){
            melody += temp3_replaced;
        }
        for(int i = 0; i < totalPlayTime % playTime; i++){
            melody += temp3_replaced[i];
        }
        
        m = replaceSharp(m);
        
        // step 3: find m from melody
        if(melody.find(m) != string::npos){
            if(answerTime < totalPlayTime){
                answerTime = totalPlayTime;
                answer = temp[2];
            }
        }
    }
    
    if(answer == ""){
        answer = "(None)";
    }
    
    return answer;
}