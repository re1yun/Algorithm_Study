#include <iostream>

using namespace std;

int main(){
    int sum = 0, max = 0, maxnum = 0;
    int number[10] = {0,};
    int count[10] = {0,};
    for(int i = 0; i < 10; i++){
        int num;        cin >> num;
        number[i] = num;
        sum += num;
        for(int j = 0; j < i; j++){
            if(number[j] == num){
                count[j]++;
                if(max < count[j]){
                    max = count[j];
                    maxnum = j;
                }
            }
        }
    }
    cout << sum / 10 << "\n" << number[maxnum]; 
    return 0;
}