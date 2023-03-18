#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int distance(int x1, int x2, int y1, int y2){
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

// return shortest distance from start coordinate to balls with one bounce from walls
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(vector<int> ball : balls){
        // x and y is distance of start and ball
        int x = abs(m - ball[0]);
        int y = abs(n - ball[1]);
        vector<int> temp;
        // check shortest distance to ball
        
        // if startX == ball[0] do not flip on x
        if(startX != ball[0]){
            // flip ball on y = 0
            temp.push_back(distance(startX, ball[0], startY, ball[1] * -1));
            // filp ball on y = n
            temp.push_back(distance(startX, ball[0], startY, n + y));
        }
        else{
            // if start is closer to y = 0, flip ball on y = 0
            if(startY < ball[1])
                temp.push_back(distance(startX, ball[0], startY, ball[1] * -1));
            else
                temp.push_back(distance(startX, ball[0], startY, n + y));
        }
        // if startY == ball[1] do not flip on y
        if(startY != ball[1]){
            // if ball is fliped on x = 0
            temp.push_back(distance(startX, ball[0] * -1, startY, ball[1]));   
            // if ball is flipped on x = m
            temp.push_back(distance(startX, m + x, startY, ball[1]));
        }  
        else{
            // if start is closer to x = 0, flip ball on x = 0
            if(startX < ball[0])
                temp.push_back(distance(startX, ball[0] * -1, startY, ball[1])); 
            else
                temp.push_back(distance(startX, m + x, startY, ball[1]));
        }
        
        answer.push_back(*min_element(temp.begin(), temp.end()));
    }
    
    return answer;
}