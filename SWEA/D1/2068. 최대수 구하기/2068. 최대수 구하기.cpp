#include <iostream>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    for(int test = 0; test < T; test++){
        int max = 0;
        for(int i = 0; i < 10; i++){
            int temp = 0;
            cin >> temp;
            if(temp > max)
                max = temp;
        }
        cout << "#" << test + 1 << " " << max << endl;
    }
    return 0;
}