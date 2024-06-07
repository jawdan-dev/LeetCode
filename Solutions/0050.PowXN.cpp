class Solution {
public:
	double myPow(double x, int n) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Early exits.
		if (n == 0 || x == 1.0) return 1.0;
		if (x == -1.0) return (n % 2 == 0) ? 1.0 : -1.0;

		// Create exponent value.
		double res = x;
		for (int i = abs(n) - 1; i >= 1;) {
			if (i % 2 == 1) {
				// Deal with additive cases.
				res *= x;
				i--;
			} else {
				// Binary move toward target.
				x *= x;
				i /= 2;
			}
		}

		// Return result.
		return (n >= 0) ? res : 1 / res;
	}
};