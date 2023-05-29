#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    // init
    int answer = 0;
    
    // algorithm
    // iterate all skill_trees
    for(string skill_tree : skill_trees){
        string tempSkill(skill.begin(), skill.end());
        bool check = true;
        // iterate all characters in skill_tree
        for(char skil : skill_tree){
            auto exist = tempSkill.find(skil);
            // if character is not found on tempSkill, move on
            if(exist == string::npos){
                continue;
            }
            // if it is first skilll, remove that skill from tempSkill and continue
            else if(exist == 0){
                tempSkill = tempSkill.substr(1, tempSkill.size() - 1);
            }
            else
                check = false;
            // if skill_tree does not make sense, quit
            if(check == false){
                break;
            }
        }
        if(check == true)
            answer++;
    }
    return answer;
}