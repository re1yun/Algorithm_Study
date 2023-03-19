#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return string includes Kim's index
string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    auto pos = find(seoul.begin(), seoul.end(), "Kim");
    int dist = distance(seoul.begin(), pos);
    answer += to_string(dist);
    answer += "에 있다";
    return answer;
}