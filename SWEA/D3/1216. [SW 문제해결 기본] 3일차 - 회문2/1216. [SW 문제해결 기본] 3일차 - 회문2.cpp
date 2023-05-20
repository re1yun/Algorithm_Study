#include <iostream>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        int answer = 0;
        // init
        // normalMap: normal map, transMap: transposed map, nDpMap: normal map's dp, tDpMap: trans map's dp
        char normalMap[100][100];
        char transMap[100][100];
        int nDpMap[100][100];
        int tDpMap[100][100];
        for(int i = 0; i < 100; i++){
        	for(int j = 0; j < 100; j++){
                char temp;	cin >> temp;
                normalMap[i][j] = temp;
                transMap[j][i] = temp;
                nDpMap[i][j] = 1;
                tDpMap[i][j] = 1;
            }
        }
        
        // algorithm
        for(int i = 0; i < 100; i++){
        	for(int j = 2; j < 100; j++){
                // if previous char is part of palindrome,
                if(nDpMap[i][j - 1] != 1){
                    // based on the length, if it is palindrome,
                    int checkIdx = j - nDpMap[i][j - 1] - 1;
                    if(checkIdx >= 0 && (normalMap[i][j] == normalMap[i][checkIdx])){
                        nDpMap[i][j] = nDpMap[i][j - 1] + 2;
                    }
                }
                // else, check if it is new beginning
                if(nDpMap[i][j] == 1){
                	if(normalMap[i][j] == normalMap[i][j - 2]){
                        nDpMap[i][j] = 3;
                    }
                    else if(normalMap[i][j] == normalMap[i][j - 1]){
                        nDpMap[i][j] = 2;
                    }
                }
                
                // if previous char is part of palindrome,
                if(tDpMap[i][j - 1] != 1){
                    // based on the length, if it is palindrome,
                    int checkIdx = j - tDpMap[i][j - 1] - 1;
                    if(checkIdx >= 0 && (transMap[i][j] == transMap[i][checkIdx])){
                        tDpMap[i][j] = tDpMap[i][j - 1] + 2;
                    }
                }
                // else, check if it is new beginning
                if(tDpMap[i][j] == 1){
                	if(transMap[i][j] == transMap[i][j - 2]){
                        tDpMap[i][j] = 3;
                    }
                    else if(transMap[i][j] == transMap[i][j - 1]){
                        tDpMap[i][j] = 2;
                    }
                }
                
                if(answer < nDpMap[i][j])
                    answer = nDpMap[i][j];
                if(answer < tDpMap[i][j])
                    answer = tDpMap[i][j];
                
            }
        }
        cout << "#" << test << " " << answer << endl;
    }
    return 0;
}