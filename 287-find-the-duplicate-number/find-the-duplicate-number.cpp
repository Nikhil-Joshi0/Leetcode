class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto it : nums){
            int i = abs(it);
            if(nums[i] < 0){
                return i;
            }

            nums[i] = -nums[i];
        }
        return 0;
    }
};