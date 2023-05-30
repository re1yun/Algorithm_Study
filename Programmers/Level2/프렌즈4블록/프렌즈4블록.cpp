/**
 * @file 프렌즈4블록.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    // init
    int answer = 0;
    vector<string> tboard;
    for(int j = 0; j < n; j++){
        string temp = "";
        for(int i = 0; i < m; i++){
            temp += board[i][j];
        }
        tboard.push_back(temp);
    }
    
    // algorithm
    while(true){
        // coord: coordination to delete
        vector<pair<int, int>> coord;
    
        // 1. find position of 2*2 tiles
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m - 1; j++){
                if(tboard[i][j] != 'x'){
                    bool check = true;
                    for(int k = i; k < i + 2; k++){
                        for(int l = j; l < j + 2; l++){
                            if(tboard[k][l] == 'x')
                                check = false;
                            if(tboard[i][j] != tboard[k][l])
                                check = false;
                        }
                    }
                    if(check == true){
                        coord.push_back(make_pair(i, j));
                    }
                }
            }
        }
        
        // if no coordinates found, then exit the algorithm
        if(coord.size() == 0)
            break;
      
        // 2. delete found position
        for(int i = 0; i < coord.size(); i++){
            int x = coord[i].first, y = coord[i].second;
            for(int j = x; j < x + 2; j++){
                for(int k = y; k < y + 2; k++){
                    if(tboard[j][k] != 'x'){
                        answer++;
                        tboard[j][k] = 'x';
                    }
                }
            }
        }
        
        // 3. update the board
        for(int i = 0; i < n; i++){
            string temp = "";
            int begin = 0;
            auto pos = tboard[i].find('x', begin);
            while(pos != string::npos){
                // get non 'x' string for temp
                temp += tboard[i].substr(begin, pos - begin);
                begin = pos;
                // get 'x' string
                string xs = "";
                while(tboard[i][begin++] == 'x')
                    xs += "x";
                begin--;
                temp = xs + temp;
                pos = tboard[i].find('x', begin);
            }
            temp += tboard[i].substr(begin);
            tboard[i] = temp;
        }    
    }
    
    return answer;
}