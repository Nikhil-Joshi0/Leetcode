class Solution {
public:

    int solve(vector<int>& arr, int k, int start){
        if(arr.size() == 1){
            return arr[0];
        }
        int idx = (start + k) % arr.size();
        arr.erase(arr.begin() + idx);
        idx = idx % arr.size();

        return solve(arr, k, idx);
    }

    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i = 0;i<n;i++){
            arr.push_back(i + 1);
        }
        int ans = solve(arr, k-1, 0);
        return ans;
    }
};