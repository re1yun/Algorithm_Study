#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int storey) {
    // init
    int answer = 0;
    string floor = to_string(storey);
    reverse(floor.begin(), floor.end());
    
    // algorithm: start from 0, find the smallest number of operands to reach storey X
    // algorithm: start from lowest number, check possible options available based on the current number
    // until we reach the ground,
    while(floor.size() != 0){
        // step 1-1: if current number is lower than 5, add to answer
        if(floor[0] - '0' < 5){
            answer += (floor[0] - '0');
        }
        // step 1-2: if current number is higher than 5, add to answer to reach 10
        else if(floor[0] - '0' > 5){
            answer += (10 - (floor[0] - '0'));
            // step 2: if this is last number, add new 1
            if(floor.size() == 1){
                floor += '1';
            }
            // step 3: if not, add 1 to next number
            else{
                floor[1] = (floor[1] - '0' + 1) + '0';    
            }
        }
        // step 1-3: if current number is 5, move based on the next number
        else{
            // step 2-1: if this is not the last floor,
            if(floor.size() > 1){
                // step 3-1: if next number is smaller than 5, just add 5
                if(floor[1] - '0' < 5){
                    answer += (floor[0] - '0');
                }
                // step 3-2: if next number is bigger than 5, increase the next number
                else{
                    answer += (10 - (floor[0] - '0'));
                    floor[1] = (floor[1] - '0' + 1) + '0';
                }    
            }
            // step 2-2: if this is last floor,
            else{
                // step 3: add 5
                answer += 5;
            }
        }
        // step 2: erase the current number
        floor.erase(0, 1);
    }
    return answer;
}