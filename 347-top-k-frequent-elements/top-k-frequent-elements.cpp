class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            minh.push({it.second, it.first});
            if(minh.size() > k)minh.pop();
        }
        vector<int> ans(k);
        for(int i = 0;i<k;i++){
            ans[i] = minh.top().second;
            minh.pop();
        }
        return ans;
    }
};