#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int N = 0;     cin >> N;
    int *array = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++){
        cin >> array[i];
    }
    int max = array[0], min = array[0];
    for(int i = 0; i < N; i++){
        if(array[i] >= max){
            max = array[i];
        } else if(array[i] <= min){
            min = array[i];
        }
    }
    cout << min << " " << max;
    return 0;
}