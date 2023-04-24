 #include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << endl;
        int N;  cin >> N;
        // curLine: current line of pascal's triangle
        int curLine[N];
        curLine[0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= i; j++){
                cout << curLine[j] << " ";
            }
            cout << endl;
            // get next line of pascal's triangle
            for(int j = i; j > 0; j--){
                curLine[j] += curLine[j - 1];
            }
            curLine[i + 1] = 1;
        }
    }
    return 0;
}