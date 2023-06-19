#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    // init
    long long answer = 0;
    int dest = n - 1;  // dest: where to go
    
    // algorithm
    while(dest >= 0){
        if(dest != n - 1){
            deliveries[dest] += deliveries[dest + 1];
            pickups[dest] += pickups[dest + 1];
        }
        int cnt = 0;
        
        // step 1. deliver and pickup all packages at dest
        while(deliveries[dest] > 0 || pickups[dest] > 0){
            deliveries[dest] -= cap;
            pickups[dest] -= cap;
            cnt++;
        }
        
        // step 2. get distance
        answer += (dest + 1) * 2 * cnt;
        dest--;
    }
    
    return answer;
}