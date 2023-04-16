#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N;  cin >> N;
        int ans = 0, curSpeed = 0;
        int com = 0, comSpeed = 0;
        for(int i = 0; i < N; i++){
            cin >> com;
            // no change in speed
            if(com == 0){
                ans += curSpeed;
            }
            // increase speed
            else if(com == 1){
                cin >> comSpeed;
                curSpeed += comSpeed;
                ans += curSpeed;
            }
            // decrease speed
            else if(com == 2){
                cin >> comSpeed;
                curSpeed = (curSpeed - comSpeed > 0) ? curSpeed - comSpeed : 0;
                ans += curSpeed;
            }
        }
        cout << ans << endl;
    }
    return 0;
}