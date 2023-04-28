/**
 * @file 빛의 경로 사이클.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return length of cycle of light path
 * @version 0.1
 * @date 2023-04-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    bool visited[500][500][4] = {false, };
    int dx[4] = {0, 1, 0, -1}; // right, down, left, up
    int dy[4] = {1, 0, -1, 0};
    int n = grid.size();
    int m = grid[0].size();

    // must check for all grids
    // define start position
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            // check for all directions
            for(int dir = 0; dir < 4; dir++){
                int cnt = 0;
                // check for cycle
                while(!visited[x][y][dir]){
                    visited[x][y][dir] = true;
                    if(grid[x][y] == 'L'){
                        dir = (dir + 3) % 4;
                    }else if(grid[x][y] == 'R'){
                        dir = (dir + 1) % 4;
                    }
                    x = (x + dx[dir] + n) % n;
                    y = (y + dy[dir] + m) % m;
                    cnt++;
                }
                // add to answer only when cycle is found
                if(cnt != 0)
                    answer.push_back(cnt);
            }
        }
    }

    // end of algorithm
    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}