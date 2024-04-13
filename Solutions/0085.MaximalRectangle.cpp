class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		// Safety first.
		if (matrix.empty() || matrix[0].empty()) return 0;

		// Create calculation information.
		struct RectInformation {
			int index, height;
		};
		stack <RectInformation> rectInformation;
		vector<int> heights(matrix[0].size() + 1, 0);

		// Calculate largest area.
		int largestArea = 0;
		for (int j = 0; j < matrix.size(); j++) {
			// Calculate heights.
			for (int i = 0; i < matrix[j].size(); i++)
				heights[i] = (matrix[j][i] == '1') ? heights[i] + 1 : 0;

			// Find largest area.
			for (int i = 0; i < heights.size(); i++) {
				int index = i;

				// Get local largest area.
				while (
					!rectInformation.empty() &&
					rectInformation.top().height > heights[i]
				) {
					// Update information.
					largestArea = max(largestArea, rectInformation.top().height * (i - rectInformation.top().index));
					index = rectInformation.top().index;
					// Remove from stack.
					rectInformation.pop();
				}

				// Add information to stack.
				rectInformation.push({ index, heights[i] });
			}

			// Clear rectangle stack.
			while (!rectInformation.empty())
				rectInformation.pop();
		}

		// Return result.
		return largestArea;
	}
};