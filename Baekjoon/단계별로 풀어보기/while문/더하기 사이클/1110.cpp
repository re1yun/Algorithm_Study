#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int N, newN, cnt = 0;     cin >> N;
    newN = N;
    while(1){
        cnt++;
        int right = newN % 10 * 10;
        int newright = newN % 10 + newN / 10;
        newN = right + newright % 10;
        if(newN == N)
            break;
    }
    cout << cnt;
    return 0;
}