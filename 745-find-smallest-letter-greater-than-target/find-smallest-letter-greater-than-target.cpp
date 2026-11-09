class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        char res;
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return nums[start%n];
    }
};