class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		// Calculate XOR value.
		int difference = nums[0], i = 1;
		const int size = nums.size();
		for (; i < size; i++) difference ^= nums[i];
		// Get difference.
		difference ^= k;
		// Calculate total steps (Count of active bits).
		return __builtin_popcount(difference);
	}
};