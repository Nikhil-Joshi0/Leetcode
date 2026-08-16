class Solution {
public:
    int myAtoi(string s) {
        int flag = 0;
        long long ans = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();
        while(i<n && s[i] == ' ')i++;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-')sign = -1;
            i++;
        }
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(ans > INT_MAX/10 || (ans == INT_MAX / 10 && digit > 7)){
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};