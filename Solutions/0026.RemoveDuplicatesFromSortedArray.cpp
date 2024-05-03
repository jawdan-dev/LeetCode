class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int write = 0;
		for (int read = 1; read < nums.size(); read++) {
			if (nums[write] == nums[read]) continue;
			nums[++write] = nums[read];
		}
		return write + 1;
	}
};