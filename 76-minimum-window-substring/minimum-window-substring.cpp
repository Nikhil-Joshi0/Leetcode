class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        string ans = "";
        int minsize = INT_MAX;
        int cur_size;
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        for (auto it : t) {
            mpp[it]++;
        }
        int size = mpp.size();
        while (j < n) {
            if (mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]]--;
                if (mpp[s[j]] == 0)
                    size--;
            }
            j++;

            if (size == 0) {
                while (true) {
                    auto it = mpp.find(s[i]);
                    if (it == mpp.end())
                        i++;
                    else if (it->second < 0) {
                        it->second++;
                        i++;
                    } else
                        break;
                }
                cur_size = j - i;
                if (cur_size < minsize) {
                    ans = s.substr(i, cur_size);
                    minsize = cur_size;
                }
            }
        }
        return ans;
    }
};
