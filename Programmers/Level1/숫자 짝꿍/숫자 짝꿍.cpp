#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// return the number of pairs of numbers that are the same
string solution(string X, string Y) {
    string answer = "";
    map<int, int> num;
    for(int i = 0; i < max(X.length(), Y.length()); i++){
        if(i < X.length() && i < Y.length())
            if(X[i] == Y[i]){
                answer += X[i];
                continue;
            }
        if(i < X.length()){
            if(num.find(X[i] - '0') == num.end())
                num[X[i] - '0'] = 1;
            else
                num[X[i] - '0']++;
        }
        if(i < Y.length()){
            if(num.find(Y[i] - '0') == num.end())
                num[Y[i] - '0'] = -1;
            else
                num[Y[i] - '0']--;
        }
        if(i < X.length())
            if(num[X[i] - '0'] <= 0)
                answer += X[i];
        if(i < Y.length())
            if(num[Y[i] - '0'] >= 0)
                answer += Y[i];
    }
    if(answer == "")
        answer = "-1";
    else
        // sort the answer in descending order
        sort(answer.begin(), answer.end(), greater<char>());
    if(answer[0] == '0')
        answer = "0";
    return answer;
}