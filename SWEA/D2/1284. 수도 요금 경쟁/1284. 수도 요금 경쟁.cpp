#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int P, Q, R, S, W;  cin >> P >> Q >> R >> S >> W;
        int A = P * W;
        int B = (W < R) ? Q : Q + (W - R) * S;
        cout << ((A < B) ? A : B) << endl;
    }
    return 0;
}