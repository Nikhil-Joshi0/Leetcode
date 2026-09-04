class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int n = nums.size();
        int last = -1;
        int l = 0;
        
            for(int r = 0;r<n;r++){
                if(nums[r] > right){
                    l = r + 1;
                }
                else if(nums[r] >= left){
                    last = r;
                }
                if(last >= l){
                    ans += last - l + 1;
                }
            }
        return ans;
    }
};