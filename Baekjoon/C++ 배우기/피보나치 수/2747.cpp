#include <iostream>

using namespace std;

int fibo[45] = {0,};

int fib(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(fibo[n] != 0){
        return fibo[n];
    }
    else{
        return fibo[n] = fib(n - 1) + fib(n - 2);
    }
}

int main(){
    int n;      cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;
    cout << fib(n);
    return 0;
}