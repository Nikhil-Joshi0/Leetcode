class Solution {
public:

    int mah(vector<int> nums){
        int n = nums.size();
        stack<pair<int, int>> st;
        int maxi = 0;
        vector<int> left(n, -1);
        vector<int> right(n,n);
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first >= nums[i])st.pop();
            if(!st.empty())left[i] = st.top().second;
            st.push({nums[i],i});
        }
        while(!st.empty())st.pop();

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top().first >= nums[i])st.pop();
            if(!st.empty())right[i] = st.top().second;
            st.push({nums[i],i});
        }

        for(int i = 0;i<n;i++){
            maxi = max(maxi, (right[i] - left[i] - 1)* nums[i]);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& nums) {
        int maxi = 0;
        vector<int> histogram(nums[0].size());
        int n = nums.size();
        int m = nums[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(nums[i][j] == '0')histogram[j] = 0;
                else histogram[j] += 1;
            }
            maxi = max(maxi, mah(histogram));
        }
        return maxi;
    }
};