#include <string>
#include <vector>
#include <iostream>

using namespace std;

// return coordinates of outer #s
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int top = wallpaper.size(), bottom = 0, left = wallpaper[0].size(), right = 0;
    for(int y = 0; y < wallpaper.size(); y++){
        for(int x = 0; x < wallpaper[y].size(); x++){
            if(wallpaper[y][x] == '#'){
                if(top > y) top = y;
                if(bottom - 1 < y) bottom = y + 1;
                if(left > x) left = x;
                if(right - 1 < x) right = x + 1;
            }
        }
    }
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(bottom);
    answer.push_back(right);
    return answer;
}