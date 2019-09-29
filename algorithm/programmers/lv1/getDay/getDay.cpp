/*
 요일구하기 알고리즘은 1월 1일이 몇요일인지만 알면 구할 수 있는 문제입니다.
 
 1월 1일을 기준으로 구하고자 하는 날짜 사이의 날짜의 간격을 구하고
 7로 나누고, 그 나머지를 현재 요일에서 더하면 되는 것입니다.
 
 그 전에 윤년임에 따라 2월이 28일이 되고, 29일이 될 수 있는 예외사항이 있겠지요?
 윤년을 구하는 공식은 다음과 같습니다.

 (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string solution(int a, int b);
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << solution(5, 24) << endl;
    return 0;
}

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string dayNames[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    
    for (int mon = 0 ; mon < a-1 ; mon++){
        totalDays += days[mon];
    }
    totalDays += b -1;
    
    return dayNames[(5 + totalDays) % 7];
}

