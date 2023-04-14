#include <iostream>

using namespace std;

int main(){
    int n = 0, k = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << k << " ";
        k *= 2;
    }
    cout << k << " ";
    return 0;
}