#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        string S;   cin >> S;
        cout << "..#";
        for(int i = 0; i < S.length() - 1; i++){
            cout << "...#";
        }
        cout << ".." << endl;
        for(int i = 0; i < S.length() * 2; i++){
            cout << ".#";
        }
        cout << "." << endl;
        for(int i = 0; i < S.length(); i++){
            cout << "#." << S[i] << ".";
        }
        cout << "#" << endl;
        for(int i = 0; i < S.length() * 2; i++){
            cout << ".#";
        }
        cout << "." << endl;
        cout << "..#";
        for(int i = 0; i < S.length() - 1; i++){
            cout << "...#";
        }
        cout << ".." << endl;
    }
    return 0;
}