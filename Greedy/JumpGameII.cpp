class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            if (i == current_end) {
                ++jumps;
                current_end = farthest;
            }
        }

        return jumps;
    }
};



class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, left = 0, right = 0;  

        while(right < nums.size()-1){
            int farthest = 0;

            for(int i = left; i <= right; i++){
                farthest = max(farthest, i + nums[i]);
            }

            left = right + 1;
            right = farthest;
            jumps++;
        }

        return jumps;
    }
};