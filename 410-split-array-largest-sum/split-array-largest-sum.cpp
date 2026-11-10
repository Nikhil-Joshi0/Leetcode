class Solution {
public:

    bool isvalid(vector<int>& nums, int mid, int k){
        int sum = 0;
        int container = 1;
        for(int i = 0;i<nums.size();i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                container++;
            }
        }
        if(container <= k)return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int ans = -1;
        int end = accumulate(nums.begin(), nums.end(), 0);
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isvalid(nums,mid,k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};