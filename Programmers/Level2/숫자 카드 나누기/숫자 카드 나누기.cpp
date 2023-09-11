#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return GCD
int GCD(int x, int y){
    int rest = 0;
    while(y != 0){
        rest = x%y;
        x = y;
        y = rest;
    }
    return x;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    // init
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    // algorithm: repeat the GCD algorithm to find GCD of arrayA and arrayB
    // step 1: find GCD of arrayA and arrayB
    int numA = arrayA[0], numB = arrayB[0];
    for(int i = 1; i < arrayA.size(); i++){
        numA = GCD(numA, arrayA[i]);
        numB = GCD(numB, arrayB[i]);
    }
    
    // step 2: get highest numA
    for(int i = numA; i > 0; i--){
        // step 2-1: if it is not a divider of numA, continue
        if(numA % i != 0){
            continue;
        }
        else{
            // step 2-2: if it has reached til 1, set the number as 1
            if(i == 1){
                numA = 1;
                break;
            }
            // step 2-3: check if any of arrayB is divided by numA, because it should not
            bool check = true;
            for(int j = 0; j < arrayB.size(); j++){
                if(arrayB[j] % i == 0){
                    check = false;
                    break;
                }
            }
            // step 2-4: if we have found the highest number on condition, set it as numA and exit
            if(check == true){
                numA = i;
                break;
            }
        }
    }
    
    // step 3: get highest numB
    for(int i = numB; i > 0; i--){
        // step 3-1: if it is not a divider of numA, continue
        if(numB % i != 0){
            continue;
        }
        else{
            // step 3-2: if it has reached til 1, set the number as 1
            if(i == 1){
                numB = 1;
                break;
            }
            // step 3-3: check if any of arrayA is divided by numA, because it should not
            bool check = true;
            for(int j = 0; j < arrayA.size(); j++){
                if(arrayA[j] % i == 0){
                    check = false;
                    break;
                }
            }
            // step 3-4: if we have found the highest number on condition, set it as numB and exit
            if(check == true){
                numB = i;
                break;
            }
        }
    }
    
    // step 4: if numA and numB is equal, then return 0 as it does not fit the condition, else return bigger number among numA and numB
    answer = (numA == numB) ? 0 : max(numA, numB);
    return answer;
}