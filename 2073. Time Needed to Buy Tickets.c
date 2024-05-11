/*
 * Problem: 2073. Time Needed to Buy Tickets
 * Link: https://leetcode.com/problems/time-needed-to-buy-tickets/
 * */

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int i, ans = 0;

    for (i = 0; i < ticketsSize; i++) {
        ans = i <= k
            ? ans + MINVAL(tickets[i], tickets[k])
            : ans + MINVAL(tickets[i], tickets[k] - 1);
    }

    return ans;
}
