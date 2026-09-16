class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        vector<int>ans;
        vector<pair<int, int>> v(mpp.begin(), mpp.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        int i = 0;
        while(k != 0){
            ans.push_back(v[i].first);
            i++;
            k--;
        }
        return ans;
    }
};