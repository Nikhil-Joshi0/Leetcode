class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int i = 0, j = 0, n = nums.size();
        vector<int> ans;

        while(j < n){
            while(!q.empty() && nums[j] > q.back()){
                q.pop_back();
            }
            q.push_back(nums[j]);

            if(j - i + 1 < k)
                j++;

            else if(j - i + 1 == k){
                ans.push_back(q.front());
                j++;
                if(nums[i] == q.front())
                    q.pop_front();
                i++;
            }
        }
        return ans;
    }
};