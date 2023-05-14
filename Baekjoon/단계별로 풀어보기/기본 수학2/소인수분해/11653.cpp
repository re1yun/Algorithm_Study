#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int N = 0;     cin >> N;
    bool* prime = new bool[N + 1];
    memset(prime, 0, sizeof(bool) * (N + 1));
    int number = 2;
    //N까지 소수 구하기
    for(int i = 2; i <= N; i++){
        if(prime[i] == false){
            for(int j = i * 2; j <= N; j+=i){
                prime[j] = true;
            }
        }
    }

    while(N > 1){
        while(true){
            if(prime[number] == false)
                break;
            else
                number++;
        }

        while(N > 1){                    //나눌 숫자가 소수일시, 
            if(N % number != 0)         //나누기가 안됨. 다른 소수 찾아 넘어가기
                break;
            else{
                N /= number;         //나누기 가능할시 나누기
                cout << number << "\n";
            }
        }

        number++;
    }
    return 0;
}