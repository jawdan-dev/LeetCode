class Solution {
public:
    int myAtoi(string s) {
        // Output storage.
        long long result = 0;

        // Variables.
        int i = 0;
        bool positive = true;

        // Ignore whitespace.
        for (; i < s.length() && s[i] == ' '; i++);

        // Get sign.
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            positive = s[i] == '+';
            i++;
        }

        // Iterate through string.
        for (; result < INT_MAX && i < s.length() && s[i] >= '0' && s[i] <= '9'; i++) {
            result *= 10;
            result += s[i] - '0';
        }

        // Clamp.
        if (positive && result > INT_MAX) return INT_MAX;
        if (!positive && -result < INT_MIN) return INT_MIN;

        // Return result.
        return positive ? result : -result;
    }
};