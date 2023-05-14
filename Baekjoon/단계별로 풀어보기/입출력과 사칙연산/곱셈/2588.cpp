#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int C = A * (B % 10);
    int D = A * ((B / 10) % 10);
    int E = A * (B / 100);
    cout << C << endl << D << endl << E << endl;
    cout << C + D * 10 + E * 100;
    return 0;
}