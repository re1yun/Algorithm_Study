#include <iostream>

using namespace std;

int main(){
    int n = 0, sum = 0;
    cin >> n;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return 0;
}