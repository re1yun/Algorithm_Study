#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int A, B;       cin >> A >> B;
        if(A >= 10 || B >= 10)
            cout << "#" << test << " " << -1 << endl;
        else
            cout << "#" << test << " " << A * B << endl;
    }
    return 0;
}