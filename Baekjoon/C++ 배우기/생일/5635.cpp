/*
나이가 제일 많은 사람은?
일이 제일 적고, 월이 제일 적고, 년이 제일 적은
*/
#include <iostream>

using namespace std;

int main(){
    int n = 0;      cin >> n;
    string name, old, young;
    int dd, mm, yy;
    int od = 99, om = 99, oy = 9999;
    int yd = 0, ym = 0, yyy = 0;
    for(int i = 0; i < n; i++){
        cin >> name >> dd >> mm >> yy;
        if(dd > yd && mm > ym && yy > yyy){
            yd = dd;
            ym = mm;
            yyy = yy;
            young = name;
        }
        if(dd < od && mm < om && yy < oy){
            od = dd;
            om = mm;
            oy = yy;
            old = name;
        }
    }
    cout << young << "\n" << old;
    
    return 0;
}