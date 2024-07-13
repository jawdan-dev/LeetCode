class Solution {
public:
	struct Data {
		int m_position, m_index;

		const bool operator <(const Data& other) const {
			return m_position < other.m_position;
		}
	};

	vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Calculation variables.
		const int n = min(positions.size(), min(healths.size(), directions.size()));
		vector<int> remaining;

		// Sort positions.
		vector<Data> sortedData;
		for (int i = 0; i < n; i++)
			sortedData.push_back({ positions[i], i });
		sort(sortedData.begin(), sortedData.end());

		// Stack based approach, working left to right.
		stack<int> workingStack;
		for (int i = 0; i < n; i++) {
			// Get true active index.
			const int selfIndex = sortedData[i].m_index;

			if (directions[selfIndex] == 'R') {
				// Add right-facing to stack to stop left-facing robots.
				workingStack.push(selfIndex);
				continue;
			}

			// All happy days if none on stack.
			if (workingStack.empty()) {
				remaining.emplace_back(selfIndex);
				continue;
			}

			// Work through stack.
			bool alive = true;
			while (!workingStack.empty()) {
				const int otherIndex = workingStack.top();

				if (healths[otherIndex] == healths[selfIndex]) {
					// Destroy both robots.
					alive = false;
					workingStack.pop();
					break;
				} else if (healths[otherIndex] > healths[selfIndex]) {
					// Destroy self.
					healths[otherIndex]--;
					alive = false;
					break;
				}

				// Destroy other.
				healths[selfIndex]--;
				workingStack.pop();
			}

			// Left-facing destroyed all robots to the left.
			if (alive) remaining.emplace_back(selfIndex);
		}

		// Get indices from stack too. 
		while (!workingStack.empty()) {
			remaining.emplace_back(workingStack.top());
			workingStack.pop();
		}

		// Convert indices to sorted health.
		sort(remaining.begin(), remaining.end());
		for (int i = 0; i < remaining.size(); i++)
			remaining[i] = healths[remaining[i]];

		return remaining;
	}
};