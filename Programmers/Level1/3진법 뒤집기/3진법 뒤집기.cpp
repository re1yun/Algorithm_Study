#include <string>
#include <vector>

using namespace std;

// convert n into 3bit, reverse it and convert it back to 10bit number
int solution(int n) {
    int answer = 0;
    // threebit: variable to store converted 3bit number
    vector<int> threebit;
    while(n > 0){
        threebit.push_back(n % 3);
        n /= 3;
    }
    // iterate through threebit reversely and convert it back to 10bit number
    for(int i = threebit.size() - 1, j = 1; i >= 0; i--, j *= 3) {
        answer += threebit[i] * j;
    }
    return answer;
}