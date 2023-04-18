#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N, M;   cin >> N >> M;
        int map[N][N];
        int ans = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> map[i][j];
        
        for(int i = 0; i <= N - M; i++){
            for(int j = 0; j <= N - M; j++){
                int temp = 0;
                for(int mi = 0; mi < M; mi++){
                    for(int mj = 0; mj < M; mj++){
                        temp += map[i + mi][j + mj];
                    }
                }
                if(temp > ans)
                    ans = temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}