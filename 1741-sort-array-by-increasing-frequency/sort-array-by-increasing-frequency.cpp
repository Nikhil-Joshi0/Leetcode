class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        minh;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            minh.push({it.second, -it.first});
        }
        int i = 0;
        while(!minh.empty()){
            int repeat = minh.top().first;
            int val = -minh.top().second;
            minh.pop();
            while(repeat--){
                nums[i++] = val;
            }
        }
        return nums;
    }
};