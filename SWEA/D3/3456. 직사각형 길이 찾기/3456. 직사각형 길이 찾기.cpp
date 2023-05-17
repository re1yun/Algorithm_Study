#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int answer = 0, temp = 0;
        cin >> answer >> temp;
        // if first two are same, last input is the answer
        if(answer == temp)
            cin >> answer;
        // if not,
        else{
        	int fin = 0;
            cin >> fin;
            // compare with current answer and if it is same, change the answer
            if(fin == answer)
                answer = temp;
            // else do not change answer
        }
        cout << "#" << test << " " << answer << endl;
    }
    return 0;
}