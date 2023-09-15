#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    // init
    long long answer = 0;
    int weight_orig[1001] = {0, };
    int weight_mult[4001] = {0, };
        
    // algorithm: use memoization
    // step 1: iterate through the weights
    for(int weight : weights){
        // step 2: find all possible weight given by 2, 3 and 4m
        for(int i = 2; i <= 4; i++){
            if(weight_mult[weight * i] != 0){
                answer += weight_mult[weight * i];
            }
        }
        
        // step 3: if same weight exists, then extract by 2, because we already added 3 but we need 1
        if(weight_orig[weight] != 0){
            answer -= (weight_orig[weight] * 2);
        }
        
        // step 4: count the weights to use for memoization
        weight_orig[weight]++;
        for(int i = 2; i <= 4; i++){
            weight_mult[weight * i]++;
        }
    }
    
    return answer;
}