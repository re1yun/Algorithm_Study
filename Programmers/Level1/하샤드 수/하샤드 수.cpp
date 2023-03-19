#include <string>
#include <vector>

using namespace std;

// return if x is Hasad number
bool solution(int x) {
    // convert x into string
    string temp = to_string(x);
    // iterate through string to get sumed value
    int sum = 0;
    for(int i = 0; i < temp.size(); i++){
        sum += (temp[i] - '0');
    }
    // check if x is Hasad number
    if(x % sum == 0)
        return true;
    else
        return false;
}