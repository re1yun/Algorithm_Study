#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkEmpty(string p);
vector<string> returnU(string p);
bool checkCorrect(string p);

string solution(string p) {
    string answer = "";
    
    // step 1. check if it is empty
    if(checkEmpty(p) == true)
        return answer;
    
    // step 2. seperate w into u and v, where u is balanced sentence and v is rest.
    vector<string> w = returnU(p);
    string u = w[0], v = w[1];
    
    // step 3. if u is correct string, return to step 1 for v.
    if(checkCorrect(u)){
        u += solution(v);
        return u;
    }
    // step 4. if u is not correct string,
    else{
        // step 4-1. create empty string with '('
        string temp = "";
        temp += '(';
        // step 4-2. return step 1 for v
        temp += solution(v);
        // step 4-3. add ')'
        temp += ')';
        // step 4-4. remove first and last character of u and add rest of string reversely
        for(int i = 1; i < u.size() - 1; i++){
            if(u[i] == '(')
                temp += ')';
            else
                temp += '(';
        }
        // step 4-5. return temp
        return temp;
    }
}

bool checkEmpty(string p){
    if(p.size() == 0)
        return true;
    else
        return false;
}

vector<string> returnU(string p){
    // init
    // left: cnt (, right: cnt )
    // temp: return string u
    int left = 0, right = 0, index = 0;
    vector<string> res;
    string temp;
    // set initial value for left and right
    if(p[index] == '(') left++;
    else right++;
    temp += p[index++];
    // loop until we get balanced string, which should not be bigger than size of original string
    while(left != right && left + right < p.size()){
        if(p[index] == '(') left++;
        else right++;
        temp += p[index++];
    }
    res.push_back(temp);
    res.push_back(p.substr(index));
    return res;
}

bool checkCorrect(string p){
    stack<char> s;
    int index = 0;
    if(p[index] == ')')
        return false;
    s.push(p[index++]);
    
    while(!s.empty() && index < p.size()){
        if(p[index] == '(')
            s.push(p[index++]);
        else{
            s.pop();
            index++;
        }
    }
    
    if(s.empty() && index == p.size())
        return true;
    else
        return false;
}