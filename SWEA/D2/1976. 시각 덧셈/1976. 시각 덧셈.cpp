#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        if(m1 + m2 > 59){
            m1 = (m1 + m2) % 60;
            h1 = (h1 + h2 + 1) % 12;
        }
        else{
            m1 += m2;
            h1 = (h1 + h2) % 12;
        }
        if(h1 == 0)
            cout << 12 << " " << m1 << endl;
        else
            cout << h1 << " " << m1 << endl;
    }
    return 0;
}