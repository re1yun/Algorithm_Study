#include <iostream>

using namespace std;

int main(){
    int sum = 0, min = 101;
    for(int i = 0; i < 7; i++){
        int num = 0;
        cin >> num;
        if(num % 2 != 0){
            sum += num;
            if(min > num){
                min = num;
            }
        }
    }
    if(sum == 0){
        cout << -1;
    }
    else{
        cout << sum << '\n' << min;
    }
    return 0;
}