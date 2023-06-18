#include <string>
#include <vector>

using namespace std;

bool checkLock(vector<vector<int>> lock);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // init
    // keys: 4 keys in rotation
    bool answer = true;
    int keys[4][key.size()][key.size()];
    for(int keycnt = 0; keycnt < 4; keycnt++){
        for(int i = 0; i < key.size(); i++){
            for(int j = 0; j < key.size(); j++){
                if(keycnt == 0)
                    keys[keycnt][i][j] = key[i][j];
                else
                    keys[keycnt][i][j] = keys[keycnt - 1][key.size() - j - 1][i];

            }
        }
    }
    
    
    // algorithm
    
    // step 1. create a bigLock
    // size: total size of bigLock, x,ylock: x,y coordinate of lock
    int size = lock.size() + (key.size() - 1) * 2;
    int bigLock[size][size];
    int xlock = key.size() - 1, ylock = key.size() - 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < xlock; j++){
            bigLock[i][j] = 2;
        }
        if(i < ylock || i >= ylock + lock.size())
            for(int j = xlock; j < xlock + lock.size(); j++){
                bigLock[i][j] = 2;
            }
        else
            for(int j = xlock; j < xlock + lock.size(); j++){
                bigLock[i][j] = lock[i - xlock][j - ylock];
            }
        for(int j = xlock + lock.size(); j < size; j++){
            bigLock[i][j] = 2;
        }
    }

    // step 2. fit key to bigLock
    // iterate through bigLock,
    for(int curY = 0; curY < size - xlock; curY++){
        for(int curX = 0; curX < size - xlock; curX++){
            answer = true;
            vector<vector<int>> temp(lock.begin(), lock.end());
            // check all 4 keys
            for(int keycnt = 0; keycnt < 4; keycnt++){
                // check key
                for(int keyY = 0; keyY < key.size(); keyY++){
                    int lockY = curY + keyY;
                    answer = true;
                    for(int keyX = 0; keyX < key.size(); keyX++){
                        int lockX = curX + keyX;
                        // step 2-1. if bigLock is out of lock boundary, skip
                        if(bigLock[lockY][lockX] == 2)
                            continue;
                        // step 2-2. if bigLock and key has same value, it does not work
                        else if(bigLock[lockY][lockX] == keys[keycnt][keyY][keyX]){
                            answer = false;
                            break;
                        }
                        // step 2-3. if bigLock is 0 and key is 1, it is working
                        else if(bigLock[lockY][lockX] == 0 && keys[keycnt][keyY][keyX] == 1){
                            temp[lockY - (key.size() - 1)][lockX - (key.size() - 1)] = 1;   
                        }
                    }
                    if(answer == false)
                        break;
                }
                // check if temp lock is filled
                if(!checkLock(temp))
                    answer = false;
                else{
                    return true;
                }
                    
            }
        }
    }
    return answer;
}

bool checkLock(vector<vector<int>> lock){
    for(int i = 0; i < lock.size(); i++){
        for(int j = 0; j < lock.size(); j++){
            if(lock[i][j] != 1)
                return false;
        }
    }
    return true;
}