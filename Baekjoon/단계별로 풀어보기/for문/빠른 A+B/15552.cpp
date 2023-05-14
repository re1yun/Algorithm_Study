#include <iostream>

using namespace std;

int main(){
    int T;      cin >> T;
    cin.tie(NULL);      ios::sync_with_stdio(false);
    for(int i = 0; i < T; i++){
        int A, B;       cin >> A >> B;
        cout << A + B << "\n";
    }
    return 0;
}