/**
 * @file 공원 산책.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief maze-like question
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    // map: normal map, mapTranspose: transposed version of map
    int map[park.size()][park[0].size()];
    int mapTranspose[park[0].size()][park.size()];
    // x, y: current position of dog
    int x, y;
    // initialize map
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[i].size(); j++){
            if(park[i][j] == 'O'){
                map[i][j] = 0;
                mapTranspose[j][i] = 0;
            }
            else if(park[i][j] == 'X'){
                map[i][j] = 1;
                mapTranspose[j][i] = 1;
            }
            else if(park[i][j] == 'S'){
                map[i][j] = 0;
                mapTranspose[j][i] = 0;
                x = i;
                y = j;
            }
        }
    }

    // for each route
    for(string route : routes){
        char dir = route[0];
        int dist = route[2] - '0';
        // ptr: iterator for map and mapTranspose
        int *ptr;
        // searching horizontally: use map
        if(dir == 'W'){
            ptr = map[x];
            if(y - dist >= 0 && (find(ptr + (y - dist), ptr + y, 1) == ptr + y)){
                // no obstacle
                y -= dist;
            }
            else{
                // obstacle
                continue;
            }
        }
        else if(dir == 'E'){
            ptr = map[x];
            if(y + dist < park[0].size() && (find(ptr + y, ptr + (y + dist), 1) == ptr + (y + dist))){
                // no obstacle
                y += dist;
            }
            else{
                // obstacle
                continue;
            }
        }
        // searching vertically: use mapTranspose
        else if(dir == 'N'){
            ptr = mapTranspose[y];
            if(x - dist >= 0 && (find(ptr + (x - dist), ptr + x, 1) == ptr + x)){
                // no obstacle
                x -= dist;
            }
            else{
                // obstacle
                continue;
            }
        }
        else if(dir == 'S'){
            ptr = mapTranspose[y];
            if(x + dist < park.size() && (find(ptr + x, ptr + (x + dist), 1) == ptr + (x + dist))){
                // no obstacle
                x += dist;
            }
            else{
                // obstacle
                continue;
            }
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}