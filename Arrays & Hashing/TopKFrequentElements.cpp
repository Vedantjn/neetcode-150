class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        for(auto i : nums)
        {
            mp[i]++;
        }

        // it.second k respect me store hoga pai max heap me

        priority_queue<pair<int,int>>pq;
        for(auto i : mp)
        {
            pq.push({i.second,i.first});
        }
        vector<int>v;
        while(k--)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};