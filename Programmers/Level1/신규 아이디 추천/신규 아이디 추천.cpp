#include <string>
#include <vector>

using namespace std;

// step1 is to change all uppercase letters to lowercase letters
string step1(string new_id){
    string answer = "";
    for(int i=0; i<new_id.length(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            answer += new_id[i] + 32;
        else
            answer += new_id[i];
    }
    return answer;
}

// step2 is to remove all characters except for lowercase letters, numbers, -, _, .
string step2(string new_id){
    string answer = "";
    for(int i=0; i<new_id.length(); i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer += new_id[i];
    }
    return answer;
}

// step3 is to convert all consecutive dots to one dot
string step3(string new_id){
    string answer = "";
    for(int i=0; i<new_id.length(); i++){
        if(new_id[i] == '.'){
            answer += new_id[i];
            while(new_id[i+1] == '.')
                i++;
        }
        else
            answer += new_id[i];
    }
    return answer;
}

// step4 is to remove the first and last dot if they exist
string step4(string new_id){
    string answer = "";
    if(new_id[0] == '.')
        new_id = new_id.substr(1);
    if(new_id[new_id.length()-1] == '.')
        new_id = new_id.substr(0, new_id.length()-1);
    return new_id;
}

// step5 is to change the empty string to "a"
string step5(string new_id){
    if(new_id == "")
        new_id = "a";
    return new_id;
}

// step6 is to remove the last character if the length is more than 15 and remove the last dot if it exists
string step6(string new_id){
    if(new_id.length() >= 16)
        new_id = new_id.substr(0, 15);
    if(new_id[new_id.length()-1] == '.')
        new_id = new_id.substr(0, new_id.length()-1);
    return new_id;
}

// step7 is to add the last character to the end of the string until the length is 3
string step7(string new_id){
    while(new_id.length() <= 2)
        new_id += new_id[new_id.length()-1];
    return new_id;
}

string solution(string new_id) {
    string answer = "";
    // run all steps
    answer = step1(new_id);
    answer = step2(answer);
    answer = step3(answer);
    answer = step4(answer);
    answer = step5(answer);
    answer = step6(answer);
    answer = step7(answer);
    
    return answer;
}