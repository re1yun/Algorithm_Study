#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return string s in descending order
string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}