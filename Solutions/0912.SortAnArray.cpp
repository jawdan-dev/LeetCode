class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = nums.size();
		vector<int> buffer(nums.size());
		vector<int>* workingBuffers[2] = { &nums, &buffer };

		// Perform merge sort (i think...)
		int currentDiv = 1;
		while (currentDiv < n) {
			// Update divider.
			const int m = currentDiv;
			currentDiv *= 2;

			// Sort.
			for (int i = 0; i < n; i += currentDiv) {
				// Get mid + end point.
				const int mid = min(i + m, n), end = min(i + currentDiv, n);

				// Work through two-pointers.
				int index = i, left = i, right = mid;
				while (left < mid && right < end) {
					if ((*workingBuffers[0])[left] < (*workingBuffers[0])[right]) {
						// Left is smaller.
						(*workingBuffers[1])[index++] = (*workingBuffers[0])[left++];
					} else {
						// Right is smaller.
						(*workingBuffers[1])[index++] = (*workingBuffers[0])[right++];
					}
				}

				// Catch any remaining values.
				while (left < mid)
					(*workingBuffers[1])[index++] = (*workingBuffers[0])[left++];
				while (right < end)
					(*workingBuffers[1])[index++] = (*workingBuffers[0])[right++];
			}

			// Swap working buffer.
			vector<int>* const tempBuffer = workingBuffers[0];
			workingBuffers[0] = workingBuffers[1];
			workingBuffers[1] = tempBuffer;
		}

		return *workingBuffers[0];
	}
};