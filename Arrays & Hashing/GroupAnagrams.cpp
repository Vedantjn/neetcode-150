class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // To store the sorted string and all its anagrams
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string T = strs[i];
            sort(T.begin(), T.end());
            mp[T].push_back(strs[i]);
        }

        // Now pushing all the anagrams(vector<string>) of one word, one by one, into result vector
        vector<vector<string>>result;

        for (auto i : mp) {
            result.push_back(i.second);
        }

        return result;
    }
};