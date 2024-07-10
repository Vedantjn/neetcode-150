class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int count = 1;
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);

        for(int i = n-1; i >= 0; i--){
            while(st.top() != -1 && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            
            int temp = st.top() - i;
            if(temp < 0){
                ans[i] = 0;
            }
            else{
                ans[i] = temp;
            }
            st.push(i);
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> ans(temperatures.size(), 0);

//         for (int i = 0; i < temperatures.size() - 1; i++) {
//             for (int j = i + 1; j < temperatures.size(); j++) {
//                 if (temperatures[j] > temperatures[i]) {
//                     ans[i] = j - i;
//                     break; 
//                 }
//             }
//         }

//         return ans;
//     }
// };
