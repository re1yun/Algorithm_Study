#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << endl;
        int N;  cin >> N;
        int i = 0, j = -1, cnt = 0;
        // init map
        int map[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                map[i][j] = 0;
            }
        }
        while(cnt != N * N){
            // proceed right only if space is available and does not have value
            while(j + 1 < N && map[i][j + 1] == 0){
                j++;
                cnt++;
                map[i][j] = cnt;
            }
            if(cnt == N * N)
                break;
            // proceed downward
            while(i - 1 >= 0 && map[i - 1][j] == 0){
                i--;
                cnt++;
                map[i][j] = cnt;
            }
            if(cnt == N * N)
                break;
            // proceed leftward
            while(j - 1 >= 0 && map[i][j - 1] == 0){
                j--;
                cnt++;
                map[i][j] = cnt;
            }
            if(cnt == N * N)
                break;
            while(i + 1 < N && map[i + 1][j] == 0){
                i++;
                cnt++;
                map[i][j] = cnt;
            }
            if(cnt == N * N)
                break;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}