class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> dup;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            dup.push_back({nums[i],i});
        }
        sort(dup.begin(), dup.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });

        vector<int> ans(k);
        for(int i = 0;i<k;i++){
            ans[i] = dup[i].second;
        }

        sort(ans.begin(), ans.end());
        
        for(int i = 0;i<k;i++){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};