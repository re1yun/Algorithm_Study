#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int max = 0, min = 1000001;
        for(int i = 0; i < 10; i++){
            string temp;    cin >> temp;
            int sum = 0;
            for(char c : temp){
                sum += (c - '0');
            }
            if(sum > max)
                max = sum;
            if(sum < min)
                min = sum;
        }
        cout << "#" << test << " " << max << " " << min << endl;
    }
    return 0;
}