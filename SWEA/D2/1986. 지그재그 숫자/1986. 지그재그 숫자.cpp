#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N;  cin >> N;
        if(N % 2 == 0) cout << -1 * (N / 2) << endl;
        else cout << N - (N - 1) / 2 << endl;
    }
    return 0;
}