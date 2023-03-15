#include <string>
#include <vector>

using namespace std;

// return GCD and LCM
vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = (n >= m) ? n : m;
    int b = (a == n) ? m : n;
    int c = a % b;
    // get GCD using uclidean
    while(c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    answer.push_back(b);
    answer.push_back(n * m / b);
    return answer;
}