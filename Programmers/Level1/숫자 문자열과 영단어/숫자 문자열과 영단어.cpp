#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// return integer of string
int solution(string s) {
    int answer = 0;
    // numbers: numbers in english
    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // find each element of numbers in s and replace into its index
    for(int i =0; i < 10; i++){
        size_t pos = s.find(numbers[i]);
        // if s contains numbers, replace
        while(pos != string::npos){
            s.replace(pos, numbers[i].size(), to_string(i));
            pos = s.find(numbers[i], pos);
        }
    }
    answer = stoi(s);
    return answer;
}