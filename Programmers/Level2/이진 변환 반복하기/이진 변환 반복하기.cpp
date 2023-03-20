#include <string>
#include <vector>

using namespace std;

// remove 0s
string removeZeros(string s){
    string temp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            temp += '1';
    }
    return temp;
}

// convert num into binary number
string convertIntoBinary(int num){
    string temp = "";
    while(num > 0){
        temp += (num % 2) + '0';
        num /= 2;
    }
    return temp;
}

// convert s into binary number by the given rules
// remove all 0 and convert remaining s into decimal number, convert it back to binary
// repeat the rule until get 1 and return number of converstion and 0s removed
vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0, zeros = 0;
    
    while(s != "1"){
        zeros += s.size();
        s = removeZeros(s);
        zeros -= s.size();
        // convert size of s into binary number
        s = convertIntoBinary(s.size());
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(zeros);
    return answer;
}