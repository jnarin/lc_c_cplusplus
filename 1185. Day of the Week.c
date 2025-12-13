/*
Problem: 1185. Day of the Week
Link: https://leetcode.com/problems/day-of-the-week/
*/
static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
char* dayOfTheWeek(int day, int month, int year) {
    const char* dayOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const int days[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, count = 0;

    for (i = 1971; i < year; i++) {
        count += isLeapYear(i) ? 366 : 365;
    }

    for (i = 0; i < month - 1; i++) {
        count += days[i];
    }

    count += day;

    return (char*)dayOfWeek[(count + 4) % 7];
}
