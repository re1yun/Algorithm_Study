#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    // init
    string answer = "";
    vector<string> numbers_str;
    for(int num : numbers)
        numbers_str.push_back(to_string(num));
    
    // algorithm
    sort(numbers_str.begin(), numbers_str.end(), [](string &a, string &b){
        return a + b > b + a;
    });
    
    if(numbers_str[0] == "0")
        answer = "0";
    else
        for(string str : numbers_str)
            answer += str;
    
    return answer;
}