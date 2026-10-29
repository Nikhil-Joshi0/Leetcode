class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp = [](string a, string b){
            if(a.size() == b.size())
                return a>b;
            return a.size() > b.size();
        };

        priority_queue<string, vector<string>, decltype(cmp)> minh(cmp);
        for(auto it : nums){
            minh.push(it);
            if(minh.size() > k){
                minh.pop();
            }
        }
        return minh.top();
    }
};