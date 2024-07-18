class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        vector<vector<int>> ans;
        
        for(auto point:points)
        {
            double x = sqrt(pow(point[0],2) + pow(point[1],2));
            pq.push({x,point});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        for (int i = 0; i < points.size(); i++) {
            int temp = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({temp, points[i]});
        }

        for (int i = 0; i < k; i++) {
            auto temp2 = pq.top();
            pq.pop();
            ans.push_back(temp2.second);
        }

        return ans;
    }
};