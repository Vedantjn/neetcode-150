class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq;
        for(int stone : stones){
            pq.push(stone);
        }

        while(pq.size() != 1){
            int stoneA = pq.top(); pq.pop();
            int stoneB = pq.top(); pq.pop();

            pq.push(abs(stoneA - stoneB));
        }

        return pq.top();
    }
};