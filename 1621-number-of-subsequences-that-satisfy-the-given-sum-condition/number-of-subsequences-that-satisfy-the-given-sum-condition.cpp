class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       int left = 0;
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int right = n - 1;
       long long ans = 0;

       int mod = 1e9 + 7;
       vector<int> power(n);
       power[0] = 1;
       for(int i = 1;i<n;i++){
        power[i] = (power[i-1] * 2) % mod;
       }

       while(right >= left){
        if(nums[left] + nums[right] <= target){
            ans = (ans + power[right - left]) % mod;
            left++;
        }
        else 
            right--;
       } 
       return ans;
    }
};