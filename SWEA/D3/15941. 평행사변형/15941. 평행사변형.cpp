#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        cout << "#" << test << " " << N * N << endl;
    }
    return 0;
}