class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int val = abs(arr[i] - x);
            maxh.push({val,i});
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        vector<int> ans(k);
        for(int i = 0;i<k;i++){
            ans[i] = maxh.top().second;
            maxh.pop();
        }
        for(int i = 0;i<k;i++){
            ans[i] = arr[ans[i]];
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};