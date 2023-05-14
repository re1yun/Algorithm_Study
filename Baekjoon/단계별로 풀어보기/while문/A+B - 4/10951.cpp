#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int A, B;
    while(1){
        cin >> A >> B;
        if(cin.eof())
            break;
        cout << A + B << endl;
    }
    return 0;
}