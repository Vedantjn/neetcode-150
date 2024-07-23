class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Check if the number of cards is divisible by groupSize
        if (hand.size() % groupSize != 0) return false;

        // Map to count the frequency of each card
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Sort the hand to process the smallest cards first
        sort(hand.begin(), hand.end());
        
        // Try to form groups starting from each card in the sorted hand
        for (int card : hand) {
            if (count[card] == 0) continue; // Skip if this card is already used up
            for (int i = 0; i < groupSize; i++) {
                if (count[card + i] > 0) {
                    count[card + i]--; // Use one occurrence of the card
                } else {
                    return false; // If we can't find the required card, return false
                }
            }
        }
        return true; // All cards successfully grouped.
    }
};