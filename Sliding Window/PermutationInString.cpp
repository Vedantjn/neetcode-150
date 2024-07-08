class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.size();
        int s2len = s2.size();
        
        if(s1len>s2len) return false;
        
        vector<int>freq_s1(26,0);
        vector<int>freq_s2(26,0);
        
        for(int i=0;i<s1len;i++)
        {
            freq_s1[s1[i]-'a']++;
            freq_s2[s2[i]-'a']++;
        }

        if(freq_s1==freq_s2)
        {
            return true;
        }
        
        for(int i=s1len;i<s2len;i++)
        {
            freq_s2[s2[i-s1len]-'a']--;
            freq_s2[s2[i]-'a']++;

            if(freq_s1==freq_s2)
            {
                return true;
            }
        }
        return false;
    }
        
};


// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int s1len = s1.length();
//         int s2len = s2.length();

//         if(s1len > s2len) return false;

//         int start = 0;
//         int end = start + s1len;
        
//         sort(s1.begin(), s1.end());

//         while(end <= s2.length()){
//             string temp = s2.substr(start, s1len);
//             sort(temp.begin(), temp.end());

//             if(s1 == temp){
//                 return true;
//             }
//             start++;
//             end++;
//         }

//         return false;
//     }
// };