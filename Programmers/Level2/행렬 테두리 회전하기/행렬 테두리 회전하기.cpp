#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    // init
    vector<int> answer;
    vector<vector<int>> map;
    int cnt = 1;
    // initialize map with cnt, since row * i + j only works when row >= column
    for(int i = 0; i < rows; i++){
        vector<int> temp;
        for(int j = 0; j < columns; j++){
            temp.push_back(cnt++);
        }
        map.push_back(temp);
    }
    


    // algorithm: purely implementation problem
    for(vector<int> query : queries){
        int xStart = query[0] - 1;
        int yStart = query[1] - 1;
        int xEnd = query[2] - 1;
        int yEnd = query[3] - 1;
        // res is initialized as 10002, as row and column can have max 100.
        int res = 10002;
        int temp = map[xStart][yStart], prev = map[xStart][yStart];
        for(int i = yStart; i < yEnd; i++){
            if(res > map[xStart][i]){
                res = map[xStart][i];
            }
            prev = map[xStart][i + 1];
            map[xStart][i + 1] = temp;
            temp = prev;
        }
        for(int i = xStart; i < xEnd; i++){
            if(res > map[i][yEnd]){
                res = map[i][yEnd];
            }
            prev = map[i + 1][yEnd];
            map[i + 1][yEnd] = temp;
            temp = prev;
        }
        for(int i = yEnd; i > yStart; i--){
            if(res > map[xEnd][i]){
                res = map[xEnd][i];
            }
            prev = map[xEnd][i - 1];
            map[xEnd][i - 1] = temp;
            temp = prev;
        }
        for(int i = xEnd; i > xStart; i--){
            if(res > map[i][yStart]){
                res = map[i][yStart];
            }
            prev = map[i - 1][yStart];
            map[i - 1][yStart] = temp;
            temp = prev;
        }
        if(res > map[xStart][yStart]){
            res = map[xStart][yStart];
        }
        
        answer.push_back(res);
    }
    
    return answer;
}