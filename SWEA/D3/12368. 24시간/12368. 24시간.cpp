#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int A, B;       cin >> A >> B;
        cout << (A + B) % 24 << endl;
    }
    return 0;
}