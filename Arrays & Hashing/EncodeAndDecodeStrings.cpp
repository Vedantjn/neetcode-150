// vector<string> input = {"hello", "world", "leetcode"};
// Codec codec;
// string encoded = codec.encode(input);
// vector<string> decoded = codec.decode(encoded);
// encoded would be something like "5#hello5#world8#leetcode".
// decoded would be {"hello", "world", "leetcode"}.

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string& str : strs) {
            encoded += to_string(str.size()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.size()) {
            int index = s.find('#', i);
            int len = stoi(s.substr(i, index - i));
            strs.push_back(s.substr(index + 1, len));
            i = index + len + 1;
        }
        return strs;
    }
};
