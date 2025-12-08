/*
Problem: 1523. Count Odd Numbers in an Interval Range
Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
*/
int countOdds(int low, int high){
    return ((high + 1) >> 1) - (low >> 1);
}
