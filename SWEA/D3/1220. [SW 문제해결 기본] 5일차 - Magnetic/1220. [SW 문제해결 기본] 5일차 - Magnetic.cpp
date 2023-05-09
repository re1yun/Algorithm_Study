#include <iostream>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        // trash is always 100...why did they use this?
        int trash;  cin >> trash;
        int map[100][100] = {0, };
        int answer = 0;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                cin >> map[j][i];
            }
        }
        // for each row,
        for(int i = 0; i < 100; i++){
            int index = 0;
            // until the end,
            while(index < 100){
                // left is N, so first collide occur when there is 2 after 1 occurs
                while(map[i][index] != 1 && index < 100){
                    index++;
                }
                // after finding 1, find 2
                while(map[i][index] != 2 && index < 100){
                    index++;
                }
                // if found, then it is colliding
                if(index < 100)
                    answer++;
            }
        }
        cout << "#" << test << " " << answer << endl;
    }
    return 0;
}