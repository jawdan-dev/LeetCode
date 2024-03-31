class Solution {
public:
    bool isPalindrome(int x) {
        // Negative check.
        if (x < 0) return false;

        // Get reversed x.
        unsigned int reversed = 0, temp = x;
        while (temp > 0) {
            reversed *= 10;
			reversed += temp % 10;
            temp /= 10;
        }

        // Check that x and its reversed counterpart match.
        return reversed == x;
    }
};