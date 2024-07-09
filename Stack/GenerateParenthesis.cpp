class Solution {
public:
    string stack;
    vector<string>res;

    void paranthesis(int open, int close, int n){
        if(close==n && open==n){
            res.push_back(stack);
            return;
        }

        if(open<n){
            stack.push_back('(');
            paranthesis(open+1,close,n);
            stack.pop_back();
        }

        if(open>close){
            stack.push_back(')');
            paranthesis(open,close+1,n);
            stack.pop_back();   
        }
    }

    vector<string> generateParenthesis(int n) {
        paranthesis(0,0,n);
        return res;
    }
};

// class Solution {
// public:
//     vector<string> res;

//     void solve(string cur, int open, int close, int n)
//     {
//         if (cur.length() == 2 * n)
//         {
//             if (open == close) res.push_back(cur);
//             return;
//         }

//         if (open < n) solve(cur + "(", open + 1, close, n);
//         if (open > close) solve(cur + ")", open, close + 1, n);
//     }

//     vector<string> generateParenthesis(int n) {
//         solve("", 0, 0, n);
//         return res;
//     }
// };