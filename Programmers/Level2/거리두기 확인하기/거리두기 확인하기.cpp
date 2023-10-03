#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// return manhattan distance
int hamDist(int x1, int x2, int y1, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

// return false if distance rule is avoided
bool checkDist(vector<string> place, int X, int Y){
    vector<vector<int>> check(5, vector<int>(5));
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    q.push(make_pair(X, Y));
    while(!q.empty()){
        int nexX = q.front().first;
        int nexY = q.front().second;
        q.pop();
        check[nexX][nexY] = 1;
        if(hamDist(X, nexX, Y, nexY) >= 3){
            continue;
        }
        for(int dir = 0; dir < 4; dir++){
            int curX = nexX + dx[dir];
            int curY = nexY + dy[dir];
            
            if(curX < 0 || curX >= place.size() || curY < 0 || curY >= place[0].size() || check[curX][curY] == 1) {
                continue;
            }
            if(hamDist(X, curX, Y, curY) >= 3){
                continue;
            }
            
            if(place[curX][curY] == 'X'){
                continue;
            }
            else if(place[curX][curY] == 'P'){
                return false;
            }
            else{
                if(hamDist(X, curX, Y, curY) <= 2){
                    q.push(make_pair(curX, curY));
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    // init
    vector<int> answer;
    
    // algorithm: BFS -> while iterating each room, if P is found, perform BFS to see if any P is violating the rule
    // step 1: iterate each room of 5
    for(int idx = 0; idx < 5; idx++){
        // step 2: iterate each row
        for(int i = 0; i < places[idx].size(); i++){
            for(int j = 0; j < places[idx][i].size(); j++){
                // step 3: find 'P'
                if(places[idx][i][j] == 'P'){
                    // step 4: check if current 'P' is violating the rule, if it does, push 0 to answer and go back to step 1.
                    if(!checkDist(places[idx], i, j)){
                        answer.push_back(0);
                        break;
                    }
                }
                // !!! if current answer size is bigger than idx, then it means answer has been added
                if(answer.size() > idx){
                    break;
                }
            }
            if(answer.size() > idx){
                break;
            }
        }
        // !!! if current answer size is equal to idx, then it means no answer has been added, so everyone is following the distance rule
        if(answer.size() == idx){
            answer.push_back(1);
        }
    }
    return answer;
}