#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    long long sum = 0;
    for(int num : arr){
        sum += num;
    }
    answer = (double)sum / arr.size();
    return answer;
}