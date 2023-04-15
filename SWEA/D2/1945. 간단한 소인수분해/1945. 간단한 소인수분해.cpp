#include <iostream>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int n = 0;
        cin >> n;
        int two = 0, three = 0, five = 0, seven = 0, eleven = 0;
        while(n % 2 == 0){
            two++;
            n /= 2;
        }
        while(n % 3 == 0){
            three++;
            n /= 3;
        }
        while(n % 5 == 0){
            five++;
            n /= 5;
        }
        while(n % 7 == 0){
            seven++;
            n /= 7;
        }
        while(n % 11 == 0){
            eleven++;
            n /= 11;
        }
        if(n != 1){
            cout << 1 << endl;
        }
        else{
            cout << two << " " << three << " " << five << " " << seven << " " << eleven << endl;
        }
    }
    return 0;
}