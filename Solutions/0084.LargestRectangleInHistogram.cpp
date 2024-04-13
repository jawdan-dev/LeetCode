class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int largestArea = 0;

		// Add element to back.
		heights.push_back(0);

		// Create rect information stack.
		struct RectInformation {
			int index, height;
		};
		stack <RectInformation> rectInformation;

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

		// Return result.
		return largestArea;
	}
};