class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxp = nums[0];
        long long minp = nums[0];
        long long ans = nums[0];
        int n = nums.size();

        for(int i = 1;i<n;i++){
            long long localmax = maxp;
            long long localmin = minp;
            long long curr = nums[i];

            maxp = max({curr, localmax * curr, localmin * curr});

            minp = min({curr, localmin * curr, localmax * curr});
            
            ans = max(ans, maxp);

        }
        return ans;
    }
};