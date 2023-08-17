#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<string> maps) {
    // init
    vector<int> answer;
    // maps_V: check visited, 0: unvisted, 1: visited
    vector<vector<int>> maps_V(maps.size(), vector<int>(maps[0].size(), 0));

    // dx & dy
    vector<int> dx {0, 1, 0, -1};
    vector<int> dy {1, 0, -1, 0};
    
    // algorithm: map searching -> bfs...?
    // step 1: run through the entire map
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            // step 2: if current map is not a land('X') or it has been already visited, skip
            if(maps[i][j] == 'X' || maps_V[i][j] == 1){
                continue;
            }
            // step 3: create temporary variables
            // temp: queue to store the land, sum: number of possible days on a land, 
            queue<pair<int, int>> temp;
            int sum = maps[i][j] - '0';
            // step 4: mark the current position as visited and add current position to temporary queue
            maps_V[i][j] = 1;
            temp.push(make_pair(i, j));
            // step 5: perform BFS, while loop until queue is empty
            while(!temp.empty()){
                // step 6: get the position from the queue and remove it
                int X = temp.front().first;
                int Y = temp.front().second;
                temp.pop();
                // step 7: check all directions
                for(int dir = 0; dir < 4; dir++){
                    int curX = X + dx[dir];
                    int curY = Y + dy[dir];
                    // step 7-1: if next position is not possible to visit due to size of map or is not a land or is already visited, continue
                    if(curX < 0 || curY < 0 || curX >= maps.size() || curY >= maps[i].size() || maps[curX][curY] == 'X' || maps_V[curX][curY] == 1){
                        continue;
                    }
                    // step 7-2: if next position is possible to visit, add to queue and mark it as visited
                    else{
                        maps_V[curX][curY] = 1;
                        temp.push(make_pair(curX, curY));
                        sum += (maps[curX][curY] - '0');
                    }
                }
            }
            // step 8: if all loop is finished, add the total number of possible days to live on a island to answer
            answer.push_back(sum);
        }
    }
    // step 9: if no possible land exists, add -1
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    // step 10: sort the answer in ascending order as required from the question
    sort(answer.begin(), answer.end());
    
    return answer;
}