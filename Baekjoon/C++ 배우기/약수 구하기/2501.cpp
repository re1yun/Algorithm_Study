#include <iostream>

using namespace std;

int main(){
    int N, K;       cin >> N >> K;
    int cnt = 0, num = 0;
    while(cnt != K && num <= N){
        num++;
        if(N % num == 0){
            cnt++;
        }
    }
    if(cnt != K){
        cout << '0';
    }
    else{
        cout << num;
    }
    return 0;
}