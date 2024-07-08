class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m>n) return "";

        unordered_map<char,int> orig; // t
        unordered_map<char,int> cnt;

        for(int i=0;i<m;i++){
            orig[t[i]]++;
            cnt[t[i]]=0;
        }

        int len = orig.size(); // number of unique chars we need
        int sz=0;
        int final_i = -1;
        int final_j = -1;
        int i = 0;
        int j = 0;
        int ans = INT_MAX;

        while(j<n){
            char temp = s[j];
            if(orig.find(temp)!=orig.end()){
                cnt[temp]++; // increased the number of this char
                if(cnt[temp] == orig[temp]) sz++; // if the amount of this specific char we need is fullfiled we will increase size

                while(len == sz){ // if sz is equal to number of unique char we found all character
                    if(j-i+1 <= ans){
                        ans = j-i+1;
                        final_i = i;
                        final_j = j;
                    }

                    if(orig.find(s[i]) != orig.end()){
                        cnt[s[i]]--;
                        if(cnt[s[i]] < orig[s[i]]) sz--;
                    }
                    i++;
                }
            }
            j++;
        }


        if(final_i == -1 || final_j == -1) return "";
        return s.substr(final_i, final_j-final_i+1);
    }
};