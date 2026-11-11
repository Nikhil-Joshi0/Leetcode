class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>> st;

    void helper(vector<int> op, vector<int> ip){
        if(ip.size() == 0){
            st.insert(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin());

        helper(op1, ip);
        helper(op2, ip);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> op;
        sort(nums.begin(), nums.end());
        helper(op, nums);
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};