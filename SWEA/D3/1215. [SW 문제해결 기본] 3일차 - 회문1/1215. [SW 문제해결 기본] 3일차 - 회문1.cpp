#include <iostream>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        // init
        char normalMap[8][8];
        char transposedMap[8][8];
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                char temp;  cin >> temp;
                normalMap[i][j] = temp;
                transposedMap[j][i] = temp;
            }
        }
        // check
        int answer = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j <= 8 - N; j++){
                if(normalMap[i][j] == normalMap[i][N - 1 + j]){
                    bool isPalindrome = true;
                    int k = 1;
                    while(k <= N / 2){
                        if(normalMap[i][j + k] == normalMap[i][N - 1 + j - k])  k++;
                        else{
                            isPalindrome = false;
                            break;
                        }
                    }
                    if(isPalindrome == true){
                        answer++;
                    }    
                }
                
                if(transposedMap[i][j] == transposedMap[i][N - 1 + j]){
                    bool isPalindrome = true;
                    int k = 1;
                    while(k <= N / 2){
                        if(transposedMap[i][j + k] == transposedMap[i][N - 1 + j - k])  k++;
                        else{
                            isPalindrome = false;
                            break;
                        }
                    }
                    if(isPalindrome == true){
                        answer++;
                    }    
                }
                
            }
        }
        cout << "#" << test << " " << answer << endl;
    }
    return 0;
}