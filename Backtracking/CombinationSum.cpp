class Solution {
public:

    void solve(int ind, vector<vector<int>>&result, vector<int>&ans, vector<int>&candidates, int target){
        if(ind == candidates.size()){
            if(target == 0){
                result.push_back(ans);
            }
                return;
        }

        if(candidates[ind] <= target){
            ans.push_back(candidates[ind]);
            solve(ind, result, ans, candidates, target-candidates[ind]);
            ans.pop_back();
        }

        solve(ind+1, result, ans, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        solve(0, result, ans, candidates, target);
        return result;
    }
};