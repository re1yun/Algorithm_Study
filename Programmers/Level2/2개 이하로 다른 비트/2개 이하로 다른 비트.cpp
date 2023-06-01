#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    // init
    vector<long long> answer;
    
    // algorithm
    for(long long num : numbers){
        // if num is an even number,
        if(num % 2 == 0){
            // next number would be just + 1 in bitwise
            answer.push_back(num + 1);
            continue;
        }
        // if num is an odd number,
        else{
            long long bit = 1;
            while(true){
                if((num & bit) == 0)
                    break;
                bit *= 2;
            }
            bit /= 2;
            // next number would be + bit, which is consecutive 1s in bitwise from rightmost side
            answer.push_back(num + bit);
        }
    }
    return answer;
}