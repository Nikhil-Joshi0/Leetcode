class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int maxi = 0;
        int n = nums.size();
        int right = 0;
        int left = 0;
        int t = 0;
        int f = 0;
        while(right < n){
            if(nums[right] == 'T')t++;
            else f++;
            right++;

            while(t > k && f > k){
                if(nums[left] == 'T')t--;
                else f--;
                left++;
            }

            maxi = max(maxi, right - left);
        }
        return maxi;
    }
};