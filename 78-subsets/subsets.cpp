class Solution {
public:
vector<vector<int>> ans;
    void helper(vector<int> op, vector<int> ip) {
        if(ip.size() == 0){
            ans.push_back(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin() + 0);

        helper(op1, ip);
        helper(op2, ip);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        helper(op, nums);
        return ans;
    }
};
