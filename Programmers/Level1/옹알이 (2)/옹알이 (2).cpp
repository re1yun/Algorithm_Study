#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    // list of words that can be pronounced
    vector<string> words = {"aya", "ye", "woo", "ma"};
    // list of words that cannot be pronounced
    vector<string> not_words = {"ayaaya", "yeye", "woowoo", "mama"};
    // iterate through babbling
    for(string bab : babbling){
        // iterate through not_words to check it it cannot be pronounced
        bool possible = true;
        for(string not_word : not_words){
            size_t pos = bab.find(not_word);
            // if not_word is found in babbling, skip to next babbling
            if(pos != string::npos){
                possible = false;
                break;
            }
        }
        if(possible == false){
            continue;
        }
        // iterate through words
        for(string word : words){
            while(bab.find(word) != string::npos){
                size_t pos = bab.find(word);
                // if word is found in babbling, replace it with xs.
                if(pos != string::npos){
                    bab.replace(pos, word.length(), "x");
                }
            }
        }
        // if bab is full of xs, increase answer by 1.
        bool check = true;
        for(char c : bab){
            if(c != 'x'){
                check = false;
                break;
            }
        }
        if(check == true) answer += 1;
    }
    return answer;
}