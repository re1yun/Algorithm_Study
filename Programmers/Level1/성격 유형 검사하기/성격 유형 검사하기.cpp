#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// return mbti
string solution(vector<string> survey, vector<int> choices) {
    // answer
    string answer = "";
    // map to store score for each attribute
    unordered_map<char, int> dictionary;
    for(int i = 0; i < survey.size(); i++){
        // calculate score for each attribute
        int score = choices[i] - 4;
        // if score is negative, take the value of the key from the map and insert into map with key of first attribute
        if(score < 0){
            if(dictionary.find(survey[i][0]) != dictionary.end())
                dictionary[survey[i][0]] += (score * -1);
            else
                dictionary.insert(make_pair(survey[i][0], (score * -1)));
        }
        // else if score is positive, insert into map with key of second attribute
        else if(score > 0){
            if(dictionary.find(survey[i][1]) != dictionary.end())
                dictionary[survey[i][1]] += score;
            else
                dictionary.insert(make_pair(survey[i][1], score));
        }
        // else, continue
        else{
            continue;
        }
    }

    // calculate mbti
    if(dictionary['R'] < dictionary['T']){
        answer += 'T';
    }
    else{
        answer += 'R';
    }
    if(dictionary['C'] < dictionary['F']){
        answer += 'F';
    }
    else{
        answer += 'C';
    }
    if(dictionary['J'] < dictionary['M']){
        answer += 'M';
    }
    else{
        answer += 'J';
    }
    if(dictionary['A'] < dictionary['N'])
        answer += 'N';
    else{
        answer += 'A';
    }
    return answer;
}
