#include <string>
#include <vector>

using namespace std;

int returnZipCnt(string s, int cnt);

int solution(string s) {
    // init
    int answer = 0;
    
    // algorithm
    // step 1. set initial value of answer, which is zipping by 1 character
    answer = returnZipCnt(s, 1);
    
    // step 2. check brute force all possible numbers
    for(int i = 2; i <= s.size() / 2; i++){
        int temp = returnZipCnt(s, i);
        if(answer > temp)
            answer = temp;
    }
    
    return answer;
}

// return length of string after zipping by cnt number
int returnZipCnt(string s, int cnt){
    // init
    int answer = 0;
    string temp = "";
    if(cnt == 1)
        temp += s[0];
    else
        temp = s.substr(0, cnt);

    // algorithm
    // check every cnt'th number
    // checking: how many times temp is repeated
    int i = cnt, checking = 1;
    for(; i <= s.size() - cnt; i += cnt){
        string cmp = s.substr(i, cnt);
        //printf("1. temp is : %s, cmp is : %s, answer is : %d\n", temp.c_str(), cmp.c_str(), answer);
        if(temp != cmp){
            temp = cmp;
            answer += cnt;
            if(checking >= 10)
                answer += 2;
            else if(checking != 1)
                answer++;
            checking = 1;
        }
        else
            checking++;
        //printf("2. temp is : %s, cmp is : %s, answer is : %d\n", temp.c_str(), cmp.c_str(), answer);
    }

    // add to answer based on checking
    if(checking == 1)
        answer += (s.size() - i + cnt);
    else if(checking >= 10)
        answer += (s.size() - i + cnt + 2);
    else
        answer += (s.size() - i + cnt + 1);
        
    //printf("final answer is : %d\n", answer);
    return answer;
}