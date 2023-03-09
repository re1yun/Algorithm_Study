#include <vector>
#include <iostream>
using namespace std;

// return number of possible cases that sum of three numbers is a prime number
int solution(vector<int> nums) {
    int answer = -1;

    // num: number of possible cases
    int num = 0;
    // sum: sum of three numbers
    int sum = 0;
    // prime: check if sum is a prime number
    bool prime = true;
    // i, j, k: index of nums
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                sum = nums[i] + nums[j] + nums[k];
                prime = true;
                for(int l = 2; l < sum; l++){
                    if(sum % l == 0){
                        prime = false;
                        break;
                    }
                }
                if(prime)
                    num++;
            }
        }
    }
    answer = num;

    return answer;
}