/*
Problem: 3516. Find Closest Person
Link: https://leetcode.com/problems/find-closest-person/
*/

int findClosest(int x, int y, int z) {
    int d1 = abs(z - x), d2 = abs(z - y);
    return d1 == d2 ? 0 : (d1 < d2 ? 1 : 2);    
}
