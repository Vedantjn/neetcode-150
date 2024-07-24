class Solution {
public:
    bool checkValidString(string s) {
        stack<int> starStack;
        stack<int> bracStack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                bracStack.push(i);
            } else if (s[i] == '*') {
                starStack.push(i);
            } else { // s[i] == ')'
                if (!bracStack.empty()) {
                    bracStack.pop();
                } else if (!starStack.empty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining opening brackets with stars
        while (!bracStack.empty() && !starStack.empty()) {
            if (bracStack.top() > starStack.top()) {
                return false; // No way to balance these
            }
            bracStack.pop();
            starStack.pop();
        }

        return bracStack.empty();
    }
};
