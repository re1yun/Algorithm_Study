#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> getDate(string str){   //string을 받아서 년,월,일로 반환하기
    vector<int> date;
    size_t pos = 0;
    string delimiter = ".";
    
    pos = str.find(delimiter);
    
    while(pos != string::npos){
        date.push_back(stoi(str.substr(0, pos)));
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
    }
    date.push_back(stoi(str));
    return date;
}

map<string, int> getTerms(vector<string> trm){
    map<string, int> terms;
    size_t pos = 0;
    string delimiter = " ";
    for(string str : trm){      //term의 한 string씩 돌면서 map에 저장
        pos = str.find(delimiter);
        string alp = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        int dat = stoi(str);
        terms.insert(pair<string, int>(alp, dat));
    }
    return terms;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    //change forms of input.
    vector<int> curDate = getDate(today);
    map<string, int> term = getTerms(terms);
    int cnt = 0;
    //go through privacies one by one.
    for(string privacy : privacies){
        cnt++;
        string delimiter = " ";
        size_t pos = privacy.find(delimiter);
        vector<int> pdate = getDate(privacy.substr(0, pos));
        string pterm = privacy.substr(pos+delimiter.length());
        //first, calculate pdate's expire date
        int exdat = (pdate[2] - 1 == 0) ? 28 : pdate[2] - 1;
        int carry = (exdat == 28) ? 1 : 0;
        int exmon = pdate[1] + term[pterm] % 12 - carry;
        carry = exmon > 12 ? 1 : 0;
        exmon = exmon > 12 ? exmon - 12 : exmon;     
        int exyea = pdate[0] + (term[pterm] / 12) + carry;
        //second, see if it is older than curDate.
        if(curDate[0] > exyea){     //exyea is smaller than curYear, destroy
            answer.push_back(cnt);
            continue;
        }
        else if(curDate[0] < exyea){//exyea is bigger than curYear, no destroy
            continue;
        }
        else{                       //exyea == curYear,
            if(curDate[1] > exmon){ //exmon is smaller than curMon, destory
                answer.push_back(cnt);
                continue;
            }
            else if(curDate[1] < exmon){
                continue;
            }
            else{
                if(curDate[2] > exdat){
                    answer.push_back(cnt);
                    continue;
                }
                else                //same or bigger, no destroy
                    continue;
            }
            
        }   
    }
    return answer;
}