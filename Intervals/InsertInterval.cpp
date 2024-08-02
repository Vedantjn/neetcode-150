class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Add all intervals that come before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals with the new interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Add all the remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for(auto it : intervals){
            if(it[1] < newInterval[0]){
                ans.push_back(it);
            }
            else if(newInterval[1] < it[0]){
                ans.push_back(newInterval);
                newInterval = it;
            }
            else{
                newInterval[0] = min(it[0], newInterval[0]);
                newInterval[1] = max(it[1], newInterval[1]);
            }
        }

        ans.push_back(newInterval);
        return ans;
    }
};