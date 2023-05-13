/**
 * @file 게임 맵 최단거리.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    // 0, 0: start point // n, m: finish point
    int n = maps[0].size();
    int m = maps.size();

    // define directions
    int dx[4] = {0, 1, 0, -1}; // up, right, down, left
    int dy[4] = {-1, 0, 1, 0}; // up, right, down, left

    queue<pair<int, int>> q;

    // insert start point
    q.push(make_pair(0, 0));

    // BFS
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // check for all directions
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // check if the next point is out of range
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            // check if the next point is wall
            if(maps[ny][nx] == 0)
                continue;

            // check if the next point is already visited
            if(maps[ny][nx] == 1){
                maps[ny][nx] = maps[y][x] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    // check if the finish point is visited
    if(maps[m-1][n-1] == 1)
        answer = -1;
    else
        answer = maps[m-1][n-1];

    return answer;
}