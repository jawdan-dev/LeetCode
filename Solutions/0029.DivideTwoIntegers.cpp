class Solution {
public:
    int divide(int dividend, int divisor) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

        unsigned int dend = dividend;
        unsigned int div = divisor;

        int sign = 1;
        if (dividend < 0) {
            dend = -(long long)dividend;
            sign = -sign;
        }
        if (divisor < 0) {
            div = -(long long)divisor;
            sign = -sign;
        }

        unsigned int result = unsigned_divide(dend, div);
        if (sign > 0 && result > INT_MAX) result = INT_MAX;

        return sign < 0 ? -result : result;
    }

    unsigned int unsigned_divide(unsigned int dividend, unsigned int divisor) {
        int bitCount = 0;
        for (int i = 0; i < 32; i++)
            if ((dividend >> i) & 0b1) 
                bitCount = i + 1;
        unsigned int q = 0, r = 0;
        for (int i = bitCount - 1; i >= 0; i--) {
            r = r << 1;
            r |= ((dividend >> i) & 0b1);
            if (r < divisor) continue;
            r -= divisor;
            q |= (0b1 << i);
        }

        return q;
    }
};