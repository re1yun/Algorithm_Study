#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int sum = 0;
        for(int i = 0; i < 10; i++){
            int temp;
            cin >> temp;
            sum += temp;
        }
        cout << floor(((float)sum + 0.5) / 10) << endl;
    }
    return 0;
}