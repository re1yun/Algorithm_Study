#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        string clap = to_string(test);
        bool isClap = false;
        for(int i = 0; i < clap.size(); i++){
            if(clap[i] == '3' || clap[i] == '6' || clap[i] == '9'){
                cout << "-";
                isClap = true;
            }
        }
        if(isClap == false)
            cout << test;
        cout << " ";
    }
    return 0;
}