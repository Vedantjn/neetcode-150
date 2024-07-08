class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, maxi = 0;
        unordered_map<char,int>mp;
        int len = -1;

        while(right < n)
        {
            mp[s[right]]++;
            maxi = max(maxi, mp[s[right]]);

            if((right-left+1) - maxi > k){
                mp[s[left]]--;
                left++;
            }
            len = max(len, (right-left+1));
            right++;   
        }
        return len;
    }
};