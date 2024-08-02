class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();

        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < intervals.size(); i++) {
            // If ans is empty or the current interval does not overlap with the previous
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                // There is an overlap, so merge the current interval with the previous one
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
