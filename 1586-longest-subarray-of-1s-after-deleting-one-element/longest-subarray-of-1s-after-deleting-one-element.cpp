class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxi = 0;
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if(n == ones)return n-1;
        int zero = 0;
        while(right < n){
            if(nums[right] == 0){
                zero++;
            }
            while(zero > 1){
                if(nums[left] == 0){
                    zero--;
                }
                left++;
            }
            maxi = max(maxi, right - left);
            right++;
        }
        return maxi;
    }
};