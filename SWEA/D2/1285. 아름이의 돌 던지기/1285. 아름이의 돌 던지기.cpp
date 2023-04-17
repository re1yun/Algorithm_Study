#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N, min = 100001, ans = 0;  cin >> N;
        for(int i = 0; i < N; i++){
            int temp;   cin >> temp;
            if(temp < 0)
                temp *= -1;
            if(temp < min){
                ans = 1;
                min = temp;
            }
            else if(temp == min){
                ans++;
            }
        }
        cout << min << " " << ans << endl;
    }
    return 0;
}