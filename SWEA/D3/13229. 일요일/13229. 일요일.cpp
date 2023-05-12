#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for(int test = 1; test <= T; test++){
        string S;   cin >> S;
        cout << "#" << test << " ";
        for(int i = 0; i < 7; i++){
            if(S == days[i]){
                cout << 7 - i << endl;
            }
        }
    }
    return 0;
}