class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int keep = 0;
		const int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] == val) continue;
			nums[keep++] = nums[i];
		}
		return keep;
	}
};