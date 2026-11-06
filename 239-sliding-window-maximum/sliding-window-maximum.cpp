class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxh;
        int i = 0, j = 0, n = nums.size();
        vector<int> ans;
        while(j < n){
            while(!maxh.empty() && nums[j] > maxh.back()){
                maxh.pop_back();
            }
            maxh.push_back(nums[j]);
            if(j-i+1 < k)j++;
            else if(j-i+1 == k){
                ans.push_back(maxh.front());
                j++;
                if(nums[i] == maxh.front())maxh.pop_front();
                i++;
            }
        }
        return ans;
    }
};