#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // Min-heap to keep track of end times of meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const auto& interval : intervals) {
            if (!minHeap.empty() && minHeap.top() <= interval.start) {
                // If the earliest ending meeting ends before or when the current meeting starts, reuse the room
                minHeap.pop();
            }
            // Add the current meeting's end time to the heap
            minHeap.push(interval.end);
        }

        // The size of the heap represents the minimum number of meeting rooms (days) required
        return minHeap.size();
    }
};
