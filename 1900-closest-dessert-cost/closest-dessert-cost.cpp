class Solution {
public:
    int ans = INT_MAX;
    int target;
    vector<int> toppingCosts;

    void dfs(int index, int curcost){
        if(index == toppingCosts.size()){
            if(abs(curcost - target) < abs(ans - target) || 
               (abs(curcost - target) == abs(ans - target) && curcost < ans)){
                ans = curcost;
            }
            return;
        }

        dfs(index + 1, curcost);
        dfs(index + 1, curcost + toppingCosts[index]);
        dfs(index + 1, curcost + 2 * toppingCosts[index]);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        this->target = target;
        this->toppingCosts = toppingCosts;

        for(int i = 0; i < baseCosts.size(); i++){
            dfs(0, baseCosts[i]);
        }

        return ans;
    }
};