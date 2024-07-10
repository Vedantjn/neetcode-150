class Solution {
public:
    bool isPossible(vector<int>& piles, int high, int mid) {
        int hour = 0;
        for (int i = 0; i < piles.size(); i++) {
            hour += (piles[i] + mid - 1) / mid; 
            if (hour > high)  
                return false;
        }
        return hour <= high;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, H, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};