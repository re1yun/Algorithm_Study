#include <iostream>

using namespace std;

int main(){
    int tprice;     cin >> tprice;
    for(int i = 0; i < 9; i++){
        int price;      cin >> price;
        tprice -= price;
    }
    cout << tprice;
    return 0;
}