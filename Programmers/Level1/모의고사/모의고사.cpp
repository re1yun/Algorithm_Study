#include <string>
#include <vector>

using namespace std;

// return the index of person who got the most answers correctly
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // 1st person's answer pattern
    vector<int> p1 = {1, 2, 3, 4, 5};
    // 2nd person's answer pattern
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    // 3rd person's answer pattern
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    // number of correct answers for each person
    vector<int> correct = {0, 0, 0};
    // iterate answers to check if the answer is correct
    for(int i = 0; i < answers.size(); i++){
        // if the answer is correct, increment the number of correct answers
        if(answers[i] == p1[i % p1.size()])
            correct[0]++;
        if(answers[i] == p2[i % p2.size()])
            correct[1]++;
        if(answers[i] == p3[i % p3.size()])
            correct[2]++;
    }
    // find the person who got the most correct answers
    int max = 0;
    for(int i = 0; i < correct.size(); i++){
        if(correct[i] > max)
            max = correct[i];
    }
    // add the index of the person who got the most correct answers to answer
    for(int i = 0; i < correct.size(); i++){
        if(correct[i] == max)
            answer.push_back(i + 1);
    }
    
    return answer;
}