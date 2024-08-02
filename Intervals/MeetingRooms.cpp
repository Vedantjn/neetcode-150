/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        // Sort intervals based on start times
        sort(intervals.begin(), intervals.end(), cmp);

        // Check for conflicts
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};
