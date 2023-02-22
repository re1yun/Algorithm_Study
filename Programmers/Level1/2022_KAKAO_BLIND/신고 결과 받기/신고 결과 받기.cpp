#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

//seperate reporter and reported from report.
vector<string> sepReport(string report){
    vector<string> temp;
    string delimiter = " ";
    string reporter = report.substr(0, report.find(delimiter));
    string reported = report.substr(report.find(delimiter) + delimiter.size());
    temp.push_back(reporter);
    temp.push_back(reported);
    return temp;
}

//create map of users to count how many mails to receive at the end.
unordered_map<string, int> setList(vector<string> id_list){
    unordered_map<string, int> temp;
    for(string str : id_list){
        temp.insert(pair<string, int>(str, 0));
    }
    return temp;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //set up map variable for users to count number of mails to receive
    unordered_map<string, int> index_list;
    index_list = setList(id_list);
    
    //set up multimap variable to count who reported who
    unordered_multimap<string, string> report_list;
    
    for(string str : report){
        //temp[0] => reporter & temp[1] => reported
        vector<string> temp = sepReport(str);
        cout << "reporter : " << temp[0] << " reported : " << temp[1] << endl;
        //iterate report_list[reported] to see if user was reported by same user before
        bool check = true;
        auto range = report_list.equal_range(temp[1]);
        for(auto it = range.first; it != range.second; ++it){
            cout << "reporter : " << temp[0] << " list : " << it->second << endl;
            if(temp[0] == it->second){
                check = false;
                break;
            }
        }
        if(check == true){
            report_list.insert(make_pair(temp[1], temp[0]));
            cout << "added key : " << temp[1] << " value : " << temp[0] << endl;
        }
    }
    cout << "--------------------------" << endl;
    //iterate all users and if reported count is bigger or equal to k, iterate report_list and count.
    for(auto str : id_list){
        cout << "user : " << str << " count : " << report_list.count(str) << endl;
        if(report_list.count(str) >= k){
            cout << "adding" << endl;
            auto range = report_list.equal_range(str);
            for(auto it = range.first; it != range.second; ++it){
                index_list[it->second]++;
                cout << "user adding : " << it->second << " count : " << index_list[it->second] << endl;
            }
        }
    }
    cout << "--------------------------" << endl;
    //iterate index_list and add received mail count to answer and return.
    for(auto str : id_list){
        cout << "user : " << str << " count : " << index_list[str] << endl;
        answer.push_back(index_list[str]);
    }
    return answer;
}