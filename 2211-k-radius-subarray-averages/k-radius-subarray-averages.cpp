class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int window = 2 * k + 1;
        vector<int> ans(n, -1);
        if (window > n) {
            return ans;
        }
        long long sum = 0;
        for (int i = 0; i < window; i++) {
            sum += nums[i];
        }
        ans[k] = sum / window;
        for (int right = window; right < n; right++) {
            sum += nums[right];
            sum -= nums[right - window];
            ans[right - k] = sum / window;
        }

        return ans;
    }
};