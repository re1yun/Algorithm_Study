#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        cout << "#" << test << " ";
        for(int i = 1; i <= N; i++){
            cout << "1/" << N << " ";
        }
        cout << endl;
    }
    return 0;
}