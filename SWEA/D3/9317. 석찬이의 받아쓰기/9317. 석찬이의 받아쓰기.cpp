#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        string temp1, temp2;    cin >> temp1 >> temp2;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(temp1[i] == temp2[i])
                cnt++;
        }
        cout << "#" << test << " " << cnt << endl;
    }
    return 0;
}