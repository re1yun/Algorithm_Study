#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int temp;
        map<int, int> tempMap;
        // transMap: transposed map
        int transMap[9][9] = {0, }, map[9][9] = {0, };
        bool check = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> temp;
                // check row
                if(tempMap.find(temp) == tempMap.end()){
                    tempMap[temp] = 1;
                }
                else{
                    check = false;
                }
                map[i][j] = temp;
                transMap[j][i] = temp;
            }
            tempMap.clear();
        }
        // sudoku requirements not met
        if(check == false){
            cout << 0 << endl;
            continue;
        }
        // check row
        for(int i = 0; i < 9; i++){
            for(int j = 1; j <= 9; j++){
                if(find(transMap[i], transMap[i] + 9, j) == (transMap[i] + 9)){
                    check = false;
                    break;
                }
            }
        }
        // sudoku requirements not met
        if(check == false){
            cout << 0 << endl;
            continue;
        }
        // check box
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                for(int k = 1; k <= 9; k++){
                    if(find(map[i], map[i] + 3, k) == (map[i] + 3)){
                        if(find(map[i + 1], map[i + 1] + 3, k) == (map[i + 1] + 3)){
                            if(find(map[i + 2], map[i + 2] + 3, k) == (map[i + 2] + 3)){
                                check = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        // sudoku requirements not met
        if(check == false){
            cout << 0 << endl;
        }
        else
            cout << 1 << endl;
    }
    return 0;
}