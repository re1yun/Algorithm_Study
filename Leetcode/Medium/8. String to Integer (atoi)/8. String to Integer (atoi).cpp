#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int myAtoi(string s) {
    long long answer = 0;
    // we can use index to indicate first + or - or digit
    // or eventually we have to iterate, so we can stick with that
    // we have to ignore any leading whitespace...so we might as well use index
    // index: first index of non leading white space
    int index = 0;
    while(index < s.size() && s[index] == ' '){
        index++;
    }
    // if it is just white space, return 0
    if(index == s.size())
        answer = 0;
    else{
        // pos: figure out if the int is positive or negative
        bool pos = true;
        // if first index is sign, then increase index, so it can start from digit
        if(s[index] == '-'){
            pos = false;
            index++;
        }
        else if(s[index] == '+')
            index++;
        // repeat until current char is digit
        for(index; index < s.size(); index++){
            // if it is not digit, exit
            if(s[index] < '0' || s[index] > '9')    break;
            // check if the answer is within the range. if it is not, set the value to limit and break;
            // else calculate
            answer = (answer * 10) + (s[index] - '0');
            if(answer > (pow(2, 31) - 1)){
                if(pos == false)
                    answer = pow(2, 31);
                else
                    answer = (pow(2, 31) - 1);
                break;
            }
        }
        if(pos == false)    answer *= -1;
    }
    return (int)answer;
}