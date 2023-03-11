#include <string>
#include <vector>
#include <string>

using namespace std;

// return if t is smaller or equal than p
bool checkNum(string t, string p){
    return stoll(t) <= stoll(p);
}

// return number of substrings from t where size is equal to p and int value is equal or lower
int solution(string t, string p) {
    int answer = 0;
    if(t.size() < p.size())
        return 1;
    for(int i = 0; i <= t.size() - p.size(); i++){
        // if first line is smaller or equal,
        if(t[i] <= p[0]){
            // see if the rest of string is smaller than p
            bool check = checkNum(t.substr(i, p.size()), p);
            if(check)
                answer++;
        }
    }
    return answer;
}