#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

// return smallest num and highest num from s
string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<int> nums;
    string num_str;
    // getline() requires second element to be string
    while(getline(ss, num_str, ' ')){
        int num = stoi(num_str);
        nums.push_back(num);
    }
    answer += to_string(*min_element(nums.begin(), nums.end()));
    answer += " ";
    answer += to_string(*max_element(nums.begin(), nums.end()));
    return answer;
}