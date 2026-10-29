class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            minh.push({nums[i],i});
            if(minh.size() > k){
                minh.pop();
            }
        }
        vector<int> ans(k);
        for(int i = 0;i<k;i++){
            ans[i] = minh.top().second;
            minh.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i = 0;i<k;i++){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};