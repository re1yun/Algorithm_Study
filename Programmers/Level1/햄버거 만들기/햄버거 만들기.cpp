#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    // convert ingredient to string
    string str = "";
    for(int i = 0; i < ingredient.size(); i++){
        str += to_string(ingredient[i]);
    }
    // find 1231, and if found, erase 1231 and move position back by 2
    int pos = 0;
    while(true){
        size_t fin = str.find("1231", pos);
        if(fin == string::npos){
            break;
        }
        str.erase(fin, 4);
        answer++;
        if(fin > 2){
            pos = fin - 3;
        }
    }
    
    return answer;
}