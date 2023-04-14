#include <iostream>

using namespace std;

int main(){
    int T = 0;
    cin >> T;
    for(int test = 0; test < T; test++){
        int a, b;
        cin >> a >> b;
        cout << "#" << test + 1 << " ";
        if(a > b)
            cout << ">" << endl;
        else if(a < b)
            cout << "<" << endl;
        else
            cout << "=" << endl;
    }
    return 0;
}