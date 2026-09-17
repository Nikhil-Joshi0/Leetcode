class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(int it : piles){
            q.push(it);
        }

        while(k != 0){
            int a = q.top();
            q.pop();
            a = (a+1)/2;
            q.push(a);
            k--;
        }
        int ans = 0;

        while(! q.empty()){
            int a = q.top();
            q.pop();
            ans += a;
        }
        return ans;
    }
};