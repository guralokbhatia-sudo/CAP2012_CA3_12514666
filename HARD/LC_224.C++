class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        signs.push(1);

        int result = 0;
        int sign = 1;

        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = signs.top();
                i++;
            } else if (s[i] == '-') {
                sign = -signs.top();
                i++;
            } else if (s[i] == '(') {
                signs.push(sign);
                i++;
            } else if (s[i] == ')') {
                signs.pop();
                i++;
            } else {
                long long number = 0;

                while (i < s.size() && isdigit(s[i])) {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }

                result += sign * number;
            }
        }

        return result;
    }
};
