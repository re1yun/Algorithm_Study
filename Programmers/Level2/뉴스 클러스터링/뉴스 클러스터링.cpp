
/**
 * @file 뉴스 클러스터링.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return calculated jacard similarity between strings
 * @version 0.1
 * @date 2023-04-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>

using namespace std;

vector<string> init(string str){
    vector<string> temp;
    for(int i = 0; i < str.size() - 1; i++){
        if(isalpha(str[i]) && isalpha(str[i + 1])){
            string tempStr;
            tempStr += tolower(str[i]);
            tempStr += tolower(str[i + 1]);
            temp.push_back(tempStr);
        }
        else
            continue;
    }
    sort(temp.begin(), temp.end());
    return temp;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> stri1, stri2, total, intersection;
    // get elements of strings
    stri1 = init(str1);
    stri2 = init(str2);
    // total: union of string elements
    set_union(stri1.begin(), stri1.end(), stri2.begin(), stri2.end(), back_inserter(total));
    // intersection: same elements present in two vectors
    set_intersection(stri1.begin(), stri1.end(), stri2.begin(), stri2.end(), back_inserter(intersection));

    //jacard: jacard index
    float jacard = total.size() == 0 ? 1 : static_cast<float>(intersection.size()) / total.size();
    answer = static_cast<int>(jacard * 65536);
    return answer;
}