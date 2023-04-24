#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    int money[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
    for(int test = 1; test <= T; test++){
        cout << "#" << test << endl;
        int N;  cin >> N;
        for(int i = 0; i < 8; i++){
            cout << N / money[i] << " ";
            N %= money[i];
        }
        cout << endl;
    }
    return 0;
}