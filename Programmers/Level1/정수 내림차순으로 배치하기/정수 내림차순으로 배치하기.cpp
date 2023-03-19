#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return n with descending order
long long solution(long long n) {
    long long answer = 0;
    // convert n into string
    string temp = to_string(n);
    // sort in descending order
    sort(temp.begin(), temp.end(), greater<char>());
    // convert back to long long
    answer = stoll(temp);
    return answer;
}