class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int n = s.size();
      int left = 0, right = 0;
      int len = 0;

      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     //   vector < int > mp(256, -1);
//       map<char, int>mp;

//       int n = s.size();
//       int left = 0, right = 0;
//       int len = 0;

//       while (right < n) {
//         if (mp.find(s[right]) != mp.end())
//           left = max(mp[s[right]] + 1, left);

//         mp[s[right]] = right;

//         len = max(len, right - left + 1);
//         right++;
//       }
//       return len;
//     }
// };