#include <iostream>

using namespace std;

int main(){
    int in = 0, out = 0, current = 0, max = 0;
    for(int i = 0; i < 10; i++){
        cin >> out >> in;
        current = current + in - out;
        if(max < current){
            max = current;
        }
    }
    cout << max;
    return 0;
}