class Solution {
public:
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
		// Speed thingies.
		// ios_base::sync_with_stdio(false);
		// cin.tie(nullptr);
		// cout.tie(nullptr);

		// Sort.
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());

		// Calculate total moves.
		int totalMoves = 0;
		const int n = min(seats.size(), students.size());
		for (int i = 0; i < n; i++) totalMoves += abs(seats[i] - students[i]);
		return totalMoves;
	}
};