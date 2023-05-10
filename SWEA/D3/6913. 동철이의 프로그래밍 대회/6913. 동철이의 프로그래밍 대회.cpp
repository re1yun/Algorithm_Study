#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N, M;   cin >> N >> M;
        // cnt => number of questions, qst => number of winners
        int winnerCnt = 0, winnerQst = 0;
        for(int i = 0; i < N; i++){
            int tempCnt = 0;
            for(int j = 0; j < M; j++){
                int temp;   cin >> temp;
                if(temp == 1)
                    tempCnt++;
            }
            if(tempCnt > winnerCnt){
                winnerCnt = tempCnt;
                winnerQst = 1;
            }
            else if(tempCnt == winnerCnt)
                winnerQst++;
        }
        cout << "#" << test << " " << winnerQst << " " << winnerCnt << endl;
    }
    return 0;
}