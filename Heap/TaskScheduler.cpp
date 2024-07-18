class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26 , 0);

        for(auto i : tasks)
            freq[i-'A']++;

        sort(freq.begin() , freq.end());

        int chunks=freq[25]-1;

        int ideal = chunks*n;

        for(int i=24; i>=0; i--){
            ideal= ideal - min(chunks, freq[i]);
        }

        if(ideal<0)
        ideal=0;
        return tasks.size()+ideal;
    }
};