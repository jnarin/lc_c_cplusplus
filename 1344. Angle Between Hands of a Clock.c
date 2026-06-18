/*
Problem: 1344. Angle Between Hands of a Clock
Link: https://leetcode.com/problems/angle-between-hands-of-a-clock/
*/

double angleClock(int hour, int minutes) {
    if (hour == 12) hour = 0;
    if (minutes == 60) minutes = 0;

    double hour_angle = 0.5 * (hour * 60 + minutes);
    double minute_angle = 6 * minutes;

    double angle = fabs(hour_angle - minute_angle);
    angle = fmin(360 - angle, angle);

    return angle;
}
