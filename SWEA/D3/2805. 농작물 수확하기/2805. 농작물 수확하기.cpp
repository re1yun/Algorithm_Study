#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        int profit = 0;
        int idx = (N - 1) / 2, range = 1;
        for(int i = 0; i < (N + 1) / 2; i++){
            string temp = "";   cin >> temp;
            for(int j = idx; j < idx + range; j++){
                profit += (temp[j] - '0');
            }
            range += 2;
            idx--;
        }
        range -= 4;
        idx += 2;
        for(int i = (N + 1) / 2; i < N; i++){
            string temp = "";   cin >> temp;
            for(int j = idx; j < idx + range; j++){
                profit += (temp[j] - '0');
            }
            range -= 2;
            idx++;
        }
        cout << "#" << test << " " << profit << endl;
    }
    return 0;
}