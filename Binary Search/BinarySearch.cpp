class Solution {
public:
    int search(vector<int>& nums, int key) {
        int start = 0;
        int end = nums.size()-1;
        int mid;

        while(start <= end){
            mid = (start + end) >> 1;
            if(nums[mid] > key) end = mid - 1;
            else if(nums[mid] < key) start = mid + 1;
            else return mid;
        }
        return -1;
    }
};