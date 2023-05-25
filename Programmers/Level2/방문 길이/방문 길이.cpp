/**
 * @file 방문 길이.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>

using namespace std;

int solution(string dirs) {
    // init
    int answer = 0;
    int check[11][11][4] = {0,};
    int curX = 5, curY = 5;
    
    // algorithm
    for(char c : dirs){
        // up
        if(c == 'U'){
            curY++;
            if(curY > 10){
                curY = 10;
                continue;
            }
            if(check[curX][curY][2] == 1)
                continue;
            check[curX][curY][2] = 1;
            check[curX][curY - 1][0] = 1;
        }
        // down
        else if(c == 'D'){
            curY--;
            if(curY < 0){
                curY = 0;
                continue;
            }
            if(check[curX][curY][0] == 1)
                continue;
            check[curX][curY][0] = 1;
            check[curX][curY + 1][2] = 1;
        }
        // right
        else if(c == 'R'){
            curX++;
            if(curX > 10){
                curX = 10;
                continue;
            }
            if(check[curX][curY][3] == 1)
                continue;
            check[curX][curY][3] = 1;
            check[curX - 1][curY][1] = 1;
        }
        // left
        else if(c == 'L'){
            curX--;
            if(curX < 0){
                curX = 0;
                continue;
            }
            if(check[curX][curY][1] == 1)
                continue;
            check[curX][curY][1] = 1;
            check[curX + 1][curY][3] = 1;
        }
        else{
            printf("wrong command!\n");
            return 0;
        }
        answer++;
    }
    
    return answer;
}