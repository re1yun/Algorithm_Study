#include <string>
#include <vector>
#include <cmath>

using namespace std;

// return power of sqrt(n) + 1 by 2
long long solution(long long n) {
    long long answer = 0;
    double sq = sqrt(n);
    // if sq is integer, following should return true
    if(sq == floor(sq) || sq == ceil(sq))
        return pow(sq + 1, 2);
    else
        return -1;
}