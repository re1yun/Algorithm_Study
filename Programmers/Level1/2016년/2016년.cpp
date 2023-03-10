#include <string>
#include <vector>

using namespace std;

// return the day of given date
string solution(int a, int b) {
    string answer = "";
    // days: number of days in each month
    int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weekDays[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    // day: number of days from 1/1 to given date
    int day = 0;
    for(int i = 0; i < a - 1; i++)
        day += days[i];
    day += b;
    int dayOfWeek = day % 7;
    
    return weekDays[dayOfWeek];
}