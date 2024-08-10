/*
 * Link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
 * Problem: 1359. Count All Valid Pickup and Delivery Options
 * */

int countOrders(int n){
    int i, MOD = 1e9 + 7;
    long ans = 1, total, pickup, curr, prev;

    n++;
    for (i = 2; i < n; i++){
        prev    = (i - 1) << 1;
        pickup  = prev + 1;
        total   = (pickup * (pickup + 1)) >> 1;

        curr    = ans * total;
        curr   %= MOD;

        ans     = curr;
    }

    return (int)(ans % MOD);

}
