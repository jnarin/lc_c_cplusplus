/*
Problem: 2037. Minimum Number of Moves to Seat Everyone
Link: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
*/

class Solution {
 public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    int ans = 0;

    ranges::sort(seats);
    ranges::sort(students);

    for (int i = 0; i < seats.size(); ++i)
      ans += abs(seats[i] - students[i]);

    return ans;
  }
};