#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N, k;   cin >> N >> k;
        // map1: normal map, map2: transposed map
        int map1[N][N];
        int map2[N][N];
        for(int i = 0; i < N; i++){
            int temp[N];
            for(int j = 0; j < N; j++){
                cin >> temp[j];
                map1[i][j] = temp[j];
                map2[j][i] = temp[j];
            }
        }
        int cnt = 0;
        for(int i = 0; i < N; i++){
            int temp1 = 0, temp2 = 0;
            for(int j = 0; j < N; j++){
                if(map1[i][j] == 1) temp1++;
                else{
                    if(temp1 == k) cnt++;
                    temp1 = 0;
                }
                if(map2[i][j] == 1) temp2++;
                else{
                    if(temp2 == k) cnt++;
                    temp2 = 0;
                }
            }
            if(temp1 == k) cnt++;
            if(temp2 == k) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}