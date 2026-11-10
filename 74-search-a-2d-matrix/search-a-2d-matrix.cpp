class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        int start = 0;
        int end = m*n - 1;
        while(start <= end){
            int mid = (start + end)/2;
            int row = mid/m;
            int col = mid%m;
            if(nums[row][col] == target)return true;
            else if(nums[row][col] > target){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return false;
    }
};