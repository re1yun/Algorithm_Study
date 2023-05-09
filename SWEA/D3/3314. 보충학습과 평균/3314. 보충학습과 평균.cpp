#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int sum = 0;
        for(int i = 0; i < 5; i++){
            int temp;   cin >> temp;
            if(temp < 40)
                sum += 40;
            else
                sum += temp;
        }
        sum /= 5;
        cout << "#" << test << " " << sum << endl;
    }
    return 0;
}