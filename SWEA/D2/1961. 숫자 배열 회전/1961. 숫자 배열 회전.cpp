#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << endl;
        int N;  cin >> N;
        int map1[N][N], map2[N][N], map3[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int temp = 0;   cin >> temp;
                map1[j][N - 1 - i] = temp;
                map2[N - 1 - i][N - 1 - j] = temp;
                map3[N - 1 - j][i] = temp;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << map1[i][j];
            }
            cout << " ";
            for(int j = 0; j < N; j++){
                cout << map2[i][j];
            }
            cout << " ";
            for(int j = 0; j < N; j++){
                cout << map3[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}