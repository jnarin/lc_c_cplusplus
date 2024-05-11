/*
 * Problem: 950. Reveal Cards In Increasing Order
 * Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 * */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());

        deque<int> d{deck[0]};

        for (int i = 1; i < deck.size(); i++) {
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }

        return {d.begin(), d.end()};
    }
};
