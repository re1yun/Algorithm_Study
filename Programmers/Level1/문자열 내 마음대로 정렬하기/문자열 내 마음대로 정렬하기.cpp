#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// struct for sorting
struct sortMem{
    char c;
    string str;
};

// return the sorted vector
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<sortMem> sortVec;
    // iterate through strings and save each member in sortVec
    for(int i = 0; i < strings.size(); i++){
        sortVec.push_back({strings[i][n], strings[i]});
    }
    sort(sortVec.begin(), sortVec.end(), [](sortMem &a, sortMem&b){
        // if a.c == b.c, sort by string
        if(a.c == b.c)
            return a.str < b.str;
        else
            return a.c < b.c;
    });
    // save the sorted vector in answer
    for(sortMem sortVar : sortVec)
        answer.push_back(sortVar.str);
    return answer;
}