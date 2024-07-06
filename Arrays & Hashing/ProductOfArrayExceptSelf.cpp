class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> answers(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            answers[i] = left[i] * right[i];
        }
        return answers;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         int product = 1;
//         int zeroCount = 0;

//         vector<int> answer(n, 0);
    
//         for(int i = 0; i < n; i++){
//             if (nums[i] != 0)
//                 product *= nums[i];
//             else
//                 zeroCount++;
//         }
        
//         if(zeroCount == 1) {
//             for (int j = 0; j < n; j++) {
//                 if (nums[j] == 0)
//                     answer[j] = product;
//             }
//         } 
//         else if(zeroCount > 1){
//             return answer;
//         }
//         else{ 
//             for (int j = 0; j < n; j++) {
//                 answer[j] = product / nums[j];
//             }
//         }
        
//         return answer;
//     }
// };