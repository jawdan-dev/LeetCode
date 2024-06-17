class Solution {
public:
	bool judgeSquareSum(int c) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Create squares.
		long long square = 0;
		for (long long i = 0; (square = i * i) <= c; i++) {
			const long long req = sqrt(c - square);
			if (square + (req * req) == c) return true;
		}

		// No square pair found.
		return false;
	}
};