#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        // since every element is about 8 digit numbers, string works as well
        vector<string> v;
        for(int i = 0; i < N; i++){
            string temp;    cin >> temp;
            v.push_back(temp);
        }
        int M;  cin >> M;
        for(int i = 0; i < M; i++){
            char c; cin >> c;
            // insert at x, y times
            if(c == 'I'){
                int x, y;
                cin >> x >> y;
                for(int j = 0; j < y; j++){
                    string temp;    cin >> temp;
                    v.insert(v.begin() + x + j, temp);
                }
            }
            // delete at x, y times
            else if(c == 'D'){
                int x, y;   cin >> x >> y;
                for(int j = 0; j < y; j++){
                    v.erase(v.begin() + x);
                }
            }
            // insert back at y times
            else if(c == 'A'){
                int y;  cin >> y;
                for(int j = 0; j < y; j++){
                    string temp;    cin >> temp;
                    v.push_back(temp);
                }
            }
        }
        // print first 10 elements
        cout << "#" << test << " ";
        for(int i = 0; i < 10; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}