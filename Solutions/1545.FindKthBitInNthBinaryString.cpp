class Solution {
public:
	const bool getBit(int n, int k) {
		// Exit case.
		if (n <= 1) return false;

		// Find binary string information.
		const int length = (1 << n) - 1;
		const int hl = length / 2;

		// Mid point is always '1'.
		if (k == hl) return true;

		// Move down a level.
		if (k < hl) return getBit(n - 1, k);

		// Return inverted and reversed bit.
		return !getBit(n - 1, length - (k + 1));
	}

	char findKthBit(int n, int k) {
		return getBit(n, k - 1) ? '1' : '0';
	}
};