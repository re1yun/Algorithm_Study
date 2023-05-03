#include <iostream>
#include <cmath>

using namespace std;

// check if the given num is palindrome
bool isPalindrome(int num){
    string temp = to_string(num);
    int leftIdx = 0, rightIdx = temp.size() - 1;
    while(leftIdx < rightIdx){
        if(temp[leftIdx] == temp[rightIdx]){
            leftIdx++;
            rightIdx--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int A, B;   cin >> A >> B;
        int answer = 0;
        for(int i = A; i <= B; i++){
            // first requirement: i should be a palindrome number
            if(isPalindrome(i)){
                // second requirement: sqrt(i) should be integer
                int temp = sqrt(i);
                if(temp * temp == i){
                    // third requirement: sqrt(i) should be a palindrome number
                    if(isPalindrome(temp)){
                        // fouth requirement: if sqrt(i) is a palindrome number, then it suits the condition
                        answer++;
                    }
                }
            }
        }

        cout << "#" << test << " " << answer << endl;
        
    }
    return 0;
}