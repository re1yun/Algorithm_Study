#include <iostream>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    for(int test = 0; test < T; test++){
        cout << "#" << test + 1 << " ";
        int sum = 0;
        for(int i = 0; i < 10; i++){
            int temp;
            cin >> temp;
            if(temp % 2 == 1)
                sum += temp;
        }
        cout << sum << endl;
    }
    return 0;
}