class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		// Two-pointers.
		sort(people.begin(), people.end());

		// Find boat count.
		int boatCount = 0;
		for (
			int left = 0, right = people.size() - 1;
			left <= right;
			right--, boatCount++
		)
			if (people[left] + people[right] <= limit)
				// Riding solo.
				left++;

		// Return boat count.
		return boatCount;
	}
};