class Solution {
public:
	int findTheWinner(int n, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculate.
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = (res + k) % i;
		return res + 1;
	}
};