class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found1 = false, found2 = false, found3 = false;
        
        for (const auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                if (triplet[0] == target[0]) found1 = true;
                if (triplet[1] == target[1]) found2 = true;
                if (triplet[2] == target[2]) found3 = true;
            }
        }
        
        return found1 && found2 && found3;
    }
};
