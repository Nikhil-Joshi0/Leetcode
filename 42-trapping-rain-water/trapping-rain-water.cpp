class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxleft(n);
        vector<int> maxright(n);
        maxleft[0] = nums[0];
        maxright[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            maxleft[i] = max(maxleft[i-1], nums[i]);
        }

        for(int i = n-2;i>=0;i--){
            maxright[i] = max(maxright[i+1], nums[i]);
        }
        int ans = 0;

        for(int i = 0;i<n;i++){
            ans += min(maxleft[i], maxright[i]) - nums[i];
        }
        return ans;
    }
};