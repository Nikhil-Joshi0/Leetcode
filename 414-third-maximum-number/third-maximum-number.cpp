class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minh;
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(st.count(nums[i])) continue;
            minh.push(nums[i]);
            st.insert(nums[i]);
            if(minh.size() > 3)minh.pop();
        }
        if(minh.size() == 2){
            minh.pop();
        }
        return minh.top();
    }
};