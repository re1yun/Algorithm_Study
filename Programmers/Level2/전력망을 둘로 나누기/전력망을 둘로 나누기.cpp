#include <string>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

// count all connected towers with given start point
int countTowers(int start1, int start2, vector<vector<int>> &map){
    int tree1 = 0, tree2 = 0;
    vector<vector<int>> local_map = map;
    
    // disconnect given points
    local_map[start1][start2] = 0;
    local_map[start2][start1] = 0;
    
    queue<int> temp;
    temp.push(start1);
    while(!temp.empty()){
        int cur_pos = temp.front();
        temp.pop();
        for(int i = 0; i < map.size(); i++){
            // if find connected tower, add it to queue and delete it from the map
            if(local_map[cur_pos][i] == 1){
                local_map[cur_pos][i] = 0;
                local_map[i][cur_pos] = 0;
                temp.push(i);
            }
        }
        tree1++;
    }
    
    temp.push(start2);
    while(!temp.empty()){
        int cur_pos = temp.front();
        temp.pop();
        for(int i = 0; i < map.size(); i++){
            // if find connected tower, add it to queue and delete it from the map
            if(local_map[cur_pos][i] == 1){
                local_map[cur_pos][i] = 0;
                local_map[i][cur_pos] = 0;
                temp.push(i);
            }
        }
        tree2++;
    }
    
    
    return tree1 - tree2;
}

int solution(int n, vector<vector<int>> wires) {
    // init
    int answer = 999;
    vector<vector<int>> map(n, vector<int>(n));
    for(vector wire: wires){
        map[wire[0] - 1][wire[1] - 1] = 1;
        map[wire[1] - 1][wire[0] - 1] = 1;
    }
    
    // algorithm: going through wires, check every possible cuttings and get smallest difference
    // step 1: iterate through wires
    for(vector<int> wire: wires){
        int s1 = wire[0] - 1;
        int s2 = wire[1] - 1;
        // step 2: calculate number of towers connected to s1 and s2
        int num = countTowers(s1, s2, map);
        // step 3: get smallest difference
        if(abs(num) < answer){
            answer = abs(num);
        }
    }
    
    return answer;
}