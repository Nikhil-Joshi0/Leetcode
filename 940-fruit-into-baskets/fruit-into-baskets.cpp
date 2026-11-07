class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int i = 0, j = 0, maxi = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        while(j < n){
            mpp[nums[j]]++;
            while(mpp.size() > 2){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0)mpp.erase(nums[i]);
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};