#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> playersRank;
    map<int, string> rankPlayers;
    for(int i = 0; i < players.size(); i++){
        playersRank.insert(make_pair(players[i], i));
        rankPlayers.insert(make_pair(i, players[i]));
    }
    for(string call : callings){
        // change player's rank
        playersRank[call]--;
        int rank = playersRank[call];
        // get player name from rank
        string temp = rankPlayers[rank];
        // change player's rank and rankPlayers
        playersRank[temp]++;
        rankPlayers[rank] = call;
        rankPlayers[rank + 1] = temp;
    }
    for(int i = 0; i < players.size(); i++){
        answer.push_back(rankPlayers[i]);
    }
    
    return answer;
}