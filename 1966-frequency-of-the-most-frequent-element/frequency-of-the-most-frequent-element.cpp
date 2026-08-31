class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        long long sum = 0;
        int ans = 0;
        int n = nums.size();
        while(right < n){
            sum += nums[right];
            long long target = nums[right];
            
            while((target) * (right - left + 1) - sum > k){
                sum -= nums[left];
                left++;
            }
            
            ans = max(ans, right - left + 1);

            right++;
        }
        return ans;
    }
};