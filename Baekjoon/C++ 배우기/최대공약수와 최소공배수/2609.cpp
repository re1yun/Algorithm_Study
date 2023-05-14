#include <iostream>

using namespace std;

int main(){
    int A, B;       cin >> A >> B;
    int a, b, c;
    if(A > B){
        a = A; b = B;
    }else{
        a = B; b = A;
    }
    while(true){
        c = a % b;
        if(c == 0){
            break;
        }
        a = b;
        b = c;
    }
    cout << b << "\n" << A * B / b;
    return 0;
}