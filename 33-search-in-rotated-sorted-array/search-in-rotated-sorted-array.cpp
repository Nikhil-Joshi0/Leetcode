class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid, next, prev, small;

        while(start <= end) {
            mid = start + (end - start) / 2;

            next = (mid + 1) % n;
            prev = (mid + n - 1) % n;

            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
                small = mid;
                break;
            }

            else if(nums[mid] > nums[end])
                start = mid + 1;

            else
                end = mid - 1;
        }
        
        start = 0;end = small - 1;
        while(start <= end){
            mid = (start + end)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid]  > target)
                end = mid - 1;
            else start = mid + 1;
        }

        start = small;
        end = n-1;
        while(start <= end){
            mid = (start + end)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};