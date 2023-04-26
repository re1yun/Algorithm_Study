#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int L, U, X;    cin >> L >> U >> X;
        if(L <= X && X <= U)
            cout << 0 << endl;
        else if(X < L)
            cout << L - X << endl;
        else if(U < X)
            cout << -1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}