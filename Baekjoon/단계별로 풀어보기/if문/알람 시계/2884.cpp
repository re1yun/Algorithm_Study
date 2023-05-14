#include <iostream>

using namespace std;

int main(){
    int H, M;       cin >> H >> M;
    M = M - 45;
    if(M < 0){
        M = 60 + M;
        //cout << M << endl;
        if(H == 0)
            H = 23;
        else
            H--;
    }
    cout << H << " " << M;
    return 0;
}