/**
 * @file 전화번호 목록.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    // get smallest length of phone_book element
    sort(phone_book.begin(), phone_book.end(), [](string a, string b){
        return a.size() < b.size();
    });
    int min_length = 21;
    for(int i = 0; i < phone_book.size(); i++){
        if(min_length == phone_book[i].size())
            continue;
        else
            min_length = phone_book[i].size();
        set<string> book;
        //book.insert(phone_book[i]);
        for(int j = i; j < phone_book.size(); j++){
            // only insert into book if temp is a full number!!
            if(phone_book[j].size() == min_length){
                if(book.insert(phone_book[j]).second == false){
                    answer = false;
                    return answer;
                }
            }
            // else, just check if prefix exist in book
            else{
                string temp = phone_book[j].substr(0, min_length);
                if(book.find(temp) != book.end()){
                    answer = false;
                    return answer;
                }
            }
        }
    }
    answer = true;
    return answer;
}