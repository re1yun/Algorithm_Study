#include <iostream>

using namespace std;

int main(){
    int p, k;
    cin >> p >> k;
    if(p > k)
        cout << p - k + 1;
    else
        cout << 999 - k + p + 1;
    return 0;
}