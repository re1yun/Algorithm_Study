#include <string>
#include <vector>
#include <cstdlib> // for abs()
#include <algorithm> // for sort() and next_permutation()

using namespace std;

long long solution(string expression) {
    // init
    long long answer = 0;
    vector<string> express, operands;
    
    // algorithm: try all possible permutations, where max possible possiblities are 9
    // step 1: divide numbers and operands and save in vector
    string temp = "";
    for(char c: expression){
        if(c - '0' >= 0 && c - '0' <= 9){
            temp += c;
        }
        else{
            express.push_back(temp);
            string oper = "";
            oper += c;
            if(find(operands.begin(), operands.end(), oper) == operands.end()){
                operands.push_back(oper);
            }
            express.push_back(oper);
            temp = "";
        }
    }
    express.push_back(temp);
    
    // step 2: get all permutations of operands vector
    vector<vector<string>> permutations;
    sort(operands.begin(), operands.end());
    
    do{
        permutations.push_back(operands);
    }
    while(next_permutation(operands.begin(), operands.end()));
    
    // step 3: find the max number from expression
    for(vector<string> perm : permutations){
        vector<string> perm_temp(express.begin(), express.end());
        for(int i = 0; i < perm.size(); i++){
            for(int idx = 1; idx < perm_temp.size() - 1; idx++){
                if(perm_temp[idx] == perm[i]){
                    if(perm_temp[idx] == "+"){
                        perm_temp[idx - 1] = to_string(stoll(perm_temp[idx - 1]) + stoll(perm_temp[idx + 1]));
                    }
                    else if(perm_temp[idx] == "-"){
                        perm_temp[idx - 1] = to_string(stoll(perm_temp[idx - 1]) - stoll(perm_temp[idx + 1]));
                    }
                    else if(perm_temp[idx] == "*"){
                        perm_temp[idx - 1] = to_string(stoll(perm_temp[idx - 1]) * stoll(perm_temp[idx + 1]));
                    }
                    
                    perm_temp.erase(perm_temp.begin() + idx, perm_temp.begin() + idx + 2);
                    idx--;
                }
            }
        }

        if(answer < abs(stoll(perm_temp[0]))){
            answer = abs(stoll(perm_temp[0]));
        }
    }
    
    return answer;
}