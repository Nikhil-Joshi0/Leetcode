class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int max_water = INT_MIN;
        while(left < right){
            if(nums[left] < nums[right]){
                max_water = max(max_water,nums[left]*(right - left));
                left++;
            }
            else{
                max_water = max(max_water, nums[right] * (right - left));
                right--;
            }
        }
        return max_water;
    }
};