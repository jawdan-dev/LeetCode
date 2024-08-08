class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Store visit order.
		int visitedIndex = 0;
		const int n = rows * cols;
		vector<vector<int>> visitedPositions(n, vector<int>(2, 0));

		// Add initial position if valid.
		if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
			visitedPositions[visitedIndex][0] = rStart;
			visitedPositions[visitedIndex][1] = cStart;
			visitedIndex++;
		}

		// Start visits.
		int activeDist = 1;
		while (visitedIndex < n) {
			const int
				targetTop = rStart - activeDist,
				targetBottom = rStart + activeDist,
				targetLeft = cStart - activeDist,
				targetRight = cStart + activeDist;

			// Top-right to bottom-right.
			if (targetRight >= 0 && targetRight < cols) {
				for (int i = targetTop + 1; i <= targetBottom; i++) {
					if (i < 0 || i >= rows) continue;
					visitedPositions[visitedIndex][0] = i;
					visitedPositions[visitedIndex][1] = targetRight;
					visitedIndex++;
				}
			}

			// Bottom-right to bottom-left.
			if (targetBottom >= 0 && targetBottom < rows) {
				for (int i = targetRight - 1; i >= targetLeft; i--) {
					if (i < 0 || i >= cols) continue;
					visitedPositions[visitedIndex][0] = targetBottom;
					visitedPositions[visitedIndex][1] = i;
					visitedIndex++;
				}
			}

			// Bottom-left to top-right.
			if (targetLeft >= 0 && targetLeft < cols) {
				for (int i = targetBottom - 1; i >= targetTop; i--) {
					if (i < 0 || i >= rows) continue;
					visitedPositions[visitedIndex][0] = i;
					visitedPositions[visitedIndex][1] = targetLeft;
					visitedIndex++;
				}
			}

			// Top-right to bottom-right.
			if (targetTop >= 0 && targetTop < rows) {
				for (int i = targetLeft + 1; i <= targetRight; i++) {
					if (i < 0 || i >= cols) continue;
					visitedPositions[visitedIndex][0] = targetTop;
					visitedPositions[visitedIndex][1] = i;
					visitedIndex++;
				}
			}

			// Increment distance.
			activeDist++;
		}

		return visitedPositions;
	}
};