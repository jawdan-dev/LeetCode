class Solution {
public:
	int numSteps(string s) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculate required moves.
		int totalMoves = 0, carry = 0;
		for (int i = s.size() - 1; i > 0; i--) {
			if (s[i] + carry == '1') {
				// Right shift + Add 1.
				totalMoves += 2;
				carry = 1;
			} else {
				// Right shift.
				totalMoves++;
			}
		}
		return totalMoves + carry;
	}
};