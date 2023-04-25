#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << endl;
        int N;  cin >> N;
        char inputChar[N];
        int inputInt[N];
        int cnt = 0;
        // get zipped file
        for(int i = 0; i < N; i++){
            cin >> inputChar[i] >> inputInt[i];
        }
        // until we reach the end,
        while(cnt < N){
            string temp;
            // add only 10 characters - because original document should have 10 characters
            for(int i = 0; i < 10; i++){
                // check if we used all the given characters or reached at the end
                if(inputInt[cnt] < 1){
                    cnt++;
                    if(cnt >= N)
                        break;
                }
                temp += inputChar[cnt];
                inputInt[cnt]--;
            }
            cout << temp << endl;
        }
    }
    return 0;
}