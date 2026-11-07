class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int unique_char = 0;
        int maxi = 0;
        while(j < n) {
            mpp[s[j]]++;
            unique_char++;
            while(unique_char != mpp.size()) {
                mpp[s[i]]--;

                if(mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
                unique_char--;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};