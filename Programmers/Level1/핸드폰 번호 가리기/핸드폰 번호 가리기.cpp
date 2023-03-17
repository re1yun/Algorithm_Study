#include <string>
#include <vector>

using namespace std;

// replace phone_number by * except last 4
string solution(string phone_number) {
    phone_number.replace(phone_number.begin(), phone_number.begin() + phone_number.size() - 4, phone_number.size() - 4, '*');
    return phone_number;
}