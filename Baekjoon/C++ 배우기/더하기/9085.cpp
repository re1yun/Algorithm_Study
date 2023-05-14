#include <iostream>

using namespace std;

int main(){
    int T;      cin >> T;
    for(int i = 0; i < T; i++){
        int N;      cin >> N;
        int res = 0;
        for(int j = 0; j < N; j++){
            int num;        cin >> num;
            res += num;
        }
        cout << res << '\n';
    }
    return 0;
}