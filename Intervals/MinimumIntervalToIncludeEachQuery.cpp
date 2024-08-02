#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort intervals based on their starting point
        sort(intervals.begin(), intervals.end());

        // Map to store the result for each query
        map<int, int> result;

        // Sort the queries
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-heap to store intervals with the smallest interval size at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int index = 0;
        for (int query : sortedQueries) {
            // Add all intervals that start before the current query
            while (index < intervals.size() && intervals[index][0] <= query) {
                int size = intervals[index][1] - intervals[index][0] + 1;
                minHeap.push({size, intervals[index][1]});
                index++;
            }

            // Remove intervals that end before the current query
            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }

            // The top of the heap is the smallest interval that covers the current query
            if (!minHeap.empty()) {
                result[query] = minHeap.top().first;
            } else {
                result[query] = -1;
            }
        }

        // Prepare the answer in the original order of queries
        vector<int> answer;
        for (int query : queries) {
            answer.push_back(result[query]);
        }

        return answer;
    }
};
