class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());
        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                // Overlapping, need to erase one interval
                count++;
                // Update end to be the minimum end to keep intervals as small as possible
                end = min(end, intervals[i][1]);
            } else {
                // No overlap, update end to current interval's end
                end = intervals[i][1];
            }
        }

        return count;
    }
};
