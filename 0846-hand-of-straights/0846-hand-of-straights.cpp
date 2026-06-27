class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) freq[card]++;

        for (auto& [card, cnt] : freq) {
            if (cnt == 0) continue;
            for (int i = 1; i < groupSize; i++) {
                freq[card + i] -= cnt;
                if (freq[card + i] < 0) return false;
            }
        }

        return true;
    }
};