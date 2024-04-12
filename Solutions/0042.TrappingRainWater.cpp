class Solution {
public:
	int trap(vector<int>& height) {
		int totalRain = 0;

		// Calculate local buckets.
		int left = 0, leftMax = height[left],
			right = height.size() - 1, rightMax = height[right];
		while (left < right) {
			// Iterate lowest side.
			if (height[left] <= height[right]) {
				// Add local left bucket max.
				totalRain += leftMax - height[left];

				// Update details.
				left++;
				if (leftMax < height[left])
					leftMax = height[left];
			} else {
				// Add local right bucket max.
				totalRain += rightMax - height[right];

				// Update details.
				right--;
				if (rightMax < height[right])
					rightMax = height[right];
			}
		}

		// Return total rain.
		return totalRain;
	}
};