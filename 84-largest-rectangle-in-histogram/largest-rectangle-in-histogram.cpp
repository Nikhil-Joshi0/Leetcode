class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<int>right(n,n);
        vector<int>left(n,-1);
        stack<pair<int, int>>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first >= nums[i])st.pop();
            if(!st.empty()){
                left[i] = st.top().second;
            }
            st.push({nums[i], i});
        }
        while(!st.empty()) st.pop();

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top().first >= nums[i])st.pop();
            if(!st.empty()){
                right[i] = st.top().second;
            }
            st.push({nums[i], i});
        }

        for(int i = 0;i<n;i++){
            int ans_i = (right[i] - left[i] - 1)*nums[i];
            maxi = max(maxi, ans_i);
        }
        return maxi;
    }
};