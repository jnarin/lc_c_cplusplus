/*
Problem: 1154. Day of the Year
Link: https://leetcode.com/problems/day-of-the-year/
*/

static bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;

    return false;
}

int dayOfYear(char* date) {
    int year, month, day, ans = 0;
    int daysBeforeMonth[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    sscanf(date, "%d-%d-%d", &year, &month, &day);

    ans += daysBeforeMonth[month - 1];

    if (month > 2 && isLeapYear(year)) {
        ans += 1;
    }

    ans += day;

    return ans;
}
