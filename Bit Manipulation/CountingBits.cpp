class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int num = i, sum = 0;
            while(num){
                sum += num%2;
                num = num>>1;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};