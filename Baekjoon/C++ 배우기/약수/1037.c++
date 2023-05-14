#include <iostream>

using namespace std;

int main(){
    int n;      cin >> n;
    int min = 1000001, max = 0;
    for(int i = 0; i < n; i++){
        int num;        cin >> num;
        if(min > num){
            min = num;
        }
        if(max < num){
            max = num;
        }
    }
    cout << min * max;
    return 0;
}