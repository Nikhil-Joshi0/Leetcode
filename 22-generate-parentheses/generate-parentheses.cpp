class Solution {
public:
    vector<string> ans;
    void helper(string op, int opening, int closing){
        if(opening == 0 && closing == 0){
            ans.push_back(op);
            return;
        }
        if(opening == closing){
            op += '(';
            opening--;
            helper(op,opening, closing);
            return;
        }
        string op1 = op;
        string op2 = op;
        op1 += '(';
        op2 += ')';
        if(opening > 0)
            helper(op1, opening - 1, closing);
        if(closing > 0)
            helper(op2, opening, closing -1);
        return;
    }

    vector<string> generateParenthesis(int n) {
        string op = "";
        op += '(';
        helper(op, n-1, n);
        return ans;
    }
};