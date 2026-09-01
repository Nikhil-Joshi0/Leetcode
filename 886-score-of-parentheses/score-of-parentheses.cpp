class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int score = 0;
        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }
            else{
                int innerscore = st.top();
                st.pop();

                int score = (innerscore == 0) ? 1 : 2 * innerscore;

                st.top() += score; 
            }
        }
        return st.top();
    }
};