#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int K;      cin >> K;
    for(int k = 0; k < K; k++){
        int P, M;       cin >> P >> M;
        int cnt = 0;
        vector<int> player(P);
        for(int i = 0; i < P; i++){
            int num;
            cin >> num;
            if(find(player.begin(), player.end(), num) != player.end()){
                cnt++;
            }
            player[i] = num;
        }
        cout << cnt << "\n";
    }
    return 0;
}