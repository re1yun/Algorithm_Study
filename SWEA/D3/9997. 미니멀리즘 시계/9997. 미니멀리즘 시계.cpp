#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int angle;  cin >> angle;
        cout << "#" << test << " " << angle / 30 << " " << angle % 30 * 2 << endl;
    }
    return 0;
}