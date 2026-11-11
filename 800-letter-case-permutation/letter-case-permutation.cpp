class Solution {
public:
    vector<string> ans;

    void helper(string op, string ip){
        if(ip.size() == 0){
            ans.push_back(op);
            return;
        }
        int num = ip[0];
        string op1 = op;
        string op2 = op;
        if(num >= 48 && num <= 57){
           op += ip[0];
           ip.erase(ip.begin());
           helper(op,ip);
        }
        else{
            op1 += ip[0];
            op2 += toupper(ip[0]);
            
            ip.erase(ip.begin());
            helper(op1, ip);
            helper(op2, ip);
        }
    }

    vector<string> letterCasePermutation(string ip) {
        string op = "";
        transform(ip.begin(), ip.end(), ip.begin(), ::tolower);
        helper(op, ip);
        return ans;
    }
};