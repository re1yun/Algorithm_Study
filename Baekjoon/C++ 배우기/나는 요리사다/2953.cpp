#include <iostream>

using namespace std;

int main(){
    int max = 0, number = 0;
    for(int i = 0; i < 5; i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            int num;        cin >> num;
            sum += num;
        }
        if(sum > max){
            number = i;
            max = sum;
        }
    }
    cout << number + 1 << " " << max;
    return 0;
}