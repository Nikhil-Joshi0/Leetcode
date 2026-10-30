class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxh;
        for(auto it : points){
            int dis = it[0]*it[0] + it[1]*it[1];
            maxh.push({dis, {it[0], it[1]}});

            if(maxh.size() > k){
                maxh.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i = 0;i<k;i++){
            ans.push_back({maxh.top().second.first, maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};