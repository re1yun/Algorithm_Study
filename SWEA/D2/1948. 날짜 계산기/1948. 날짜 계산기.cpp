#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int month1, date1, month2, date2;
        cin >> month1 >> date1 >> month2 >> date2;
        int total1 = 0, total2 = 0;
        for(int i = 0; i < month1 - 1; i++){
            total1 += month[i];
        }
        total1 += date1;
        for(int i = 0; i < month2 - 1; i++){
            total2 += month[i];
        }
        total2 += date2;
        cout << total2 - total1 + 1 << endl;
    }
    return 0;
}