#include <iostream>
#include <stack>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        int N;  cin >> N;
        string X;   cin >> X;
        stack<int> s;
        for(char c : X){
            int num = c - '0';
            if(s.empty())
                s.push(num);
            else{
                if(s.top() == num)
                    s.pop();
                else
                    s.push(num);
            }
        }
        string temp = "";
        while(!s.empty()){
            temp += to_string(s.top());
            s.pop();
        }
        cout << "#" << test << " ";
        for(int i = temp.length() - 1; i >= 0; i--){
            cout << temp[i];
        }
        cout << endl;
    }
    return 0;
}