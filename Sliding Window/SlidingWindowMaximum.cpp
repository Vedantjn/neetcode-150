class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
            vector<int>result;
            deque<int>dq;
        
        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;

//         int start = 0;
//         int end = start + k - 1;

//         while (end < n) {
//             int maxi = INT_MIN;
//             for (int i = start; i <= end; i++) {
//                 maxi = max(maxi, nums[i]);
//             }
//             ans.push_back(maxi);
//             start++;
//             end++;
//         }

//         return ans;
//     }
// };
