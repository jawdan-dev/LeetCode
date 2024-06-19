class Solution {
public:
	struct BloomInformation {
		int m_start, m_length;

		BloomInformation(int start, int length) :
			m_start(start), m_length(length) {}
	};

	int m_targetLength, m_remainingFlowers;
	void updateRemaining(const int oldLength) {
		// Calculate new used.
		const int
			oldUsed = oldLength / m_targetLength,
			mergedUsed = (oldLength + 1) / m_targetLength;
		// Update k.
		m_remainingFlowers -= mergedUsed - oldUsed;
	}
	void updateRemaining(const int oldLength1, const int oldLength2) {
		// Calculate new used.
		const int
			oldUsed = (oldLength1 / m_targetLength) + (oldLength2 / m_targetLength),
			mergedUsed = (oldLength1 + oldLength2) / m_targetLength;
		// Update k.
		m_remainingFlowers -= mergedUsed - oldUsed;
	}

	int minDays(vector<int>& bloomDay, int m, int k) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Early exit.
		const long long totalRequired = (long long)m * (long long)k;
		if (totalRequired > bloomDay.size()) return -1;

		// Calculation variables.
		m_remainingFlowers = m;
		m_targetLength = k;
		const int n = bloomDay.size();

		// Setup day pairs.
		vector<pair<int, int>> days;
		for (int i = 0; i < n; i++)
			days.emplace_back(bloomDay[i], i);
		sort(days.begin(), days.end());

		// Early exit.
		if (totalRequired == bloomDay.size()) return days.back().first;

		// Calculate.
		int activeDayIndex = 0;
		vector<BloomInformation*> bloomInfo(n, nullptr);
		for (; activeDayIndex < n && m_remainingFlowers > 0; activeDayIndex++) {
			const int index = days[activeDayIndex].second;

			// Merge left.
			if (index - 1 >= 0 && bloomInfo[index - 1] != nullptr) {
				BloomInformation* const mergeInfo = bloomInfo[index - 1];
				// Merge.
				updateRemaining(mergeInfo->m_length);
				mergeInfo->m_length++;
				bloomInfo[index] = mergeInfo;
			}

			// Merge right.
			if (index + 1 < n && bloomInfo[index + 1] != nullptr) {
				BloomInformation* const mergeInfo = bloomInfo[index + 1];

				if (bloomInfo[index] == nullptr) {
					// Merge (simple).
					updateRemaining(mergeInfo->m_length);
					mergeInfo->m_start = index;
					mergeInfo->m_length++;
					bloomInfo[index] = mergeInfo;
				} else {
					BloomInformation* const otherInfo = bloomInfo[index];
					// Merge (complex).
					updateRemaining(otherInfo->m_length, mergeInfo->m_length);
					for (int j = 0; j < mergeInfo->m_length; j++)
						bloomInfo[mergeInfo->m_start + j] = otherInfo;
					otherInfo->m_length += mergeInfo->m_length;
					// Cleanup?
					delete mergeInfo;
				}
			}

			// Create bloom info if no merge occured.
			if (bloomInfo[index] == nullptr) {
				bloomInfo[index] = new BloomInformation(index, 1);
				updateRemaining(0);
			}
		}

		// Cleanup is for the 'week' and 'sow'.
		return m_remainingFlowers <= 0 ? days[activeDayIndex - 1].first : -1;
	}
};