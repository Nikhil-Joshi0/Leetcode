class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> nums;
        for(auto it : points){
            int a = it[0];
            int b = it[1];

            int dis = (a*a + b*b);

            nums.push_back({dis, it});
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        vector<vector<int>> ans;
        while(k != 0){
            ans.push_back(nums[i].second);
            k--;i++;
        }
        return ans;
    }
};