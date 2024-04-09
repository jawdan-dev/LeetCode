class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		// Get initial time.
		int time = 0;
		for (int i = 0; i <= k; i++) {
			time++;
			tickets[i]--;
		}

		// Early exit.
		if (tickets[k] <= 0) return time;

		// Circular loop time.
		for (int i = 0; i < tickets.size(); i++) {
			const int index = (i + k + 1) % tickets.size();
			if (tickets[index] >= tickets[k]) {
				time += tickets[k];
				tickets[index] -= tickets[k];
			} else {
				time += tickets[index];
				tickets[index] = 0;
			}
		}

		// Return time.
		return time;
	}
};