class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> arr;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            arr.push_back({nums[i], cost[i]});
        }  
        sort(arr.begin(), arr.end());
        long long tcost = accumulate(cost.begin(), cost.end(), 0LL);
        long long half = tcost/2;
        long long sum = 0;
        long long target;
        for(int i = 0;i<n;i++){
            sum += arr[i].second;
            if(sum > half){
                target = arr[i].first;
                break;
            }
        }
        long long mincost = 0;
        for(int i = 0;i<n;i++){
            mincost += abs(nums[i] - target) * cost[i];
        }
        return mincost;
    }
};