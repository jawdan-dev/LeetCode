class Solution {
public:
	int m_distanceToCharacter[26][26];

	void floydWarshallAlgorithm(const vector<char>& original, const vector<char>& changed, const vector<int>& cost) {
		// Initialize data.
		const int extent = min(
			sizeof(m_distanceToCharacter) / sizeof(*m_distanceToCharacter),
			sizeof(*m_distanceToCharacter) / sizeof(**m_distanceToCharacter)
		);
		for (int i = 0; i < extent; i++) {
			for (int j = 0; j < extent; j++)
				m_distanceToCharacter[i][j] = 10e6 + 1;
			m_distanceToCharacter[i][i] = 0;
		}

		// Add initial scores.
		const int n = min(original.size(), changed.size());
		for (int i = 0; i < n; i++) {
			const int
				row = original[i] - 'a',
				col = changed[i] - 'a';

			m_distanceToCharacter[row][col] = min(
				m_distanceToCharacter[row][col],
				cost[i]
			);
		}

		// Minimize routes.
		for (int i = 0; i < extent; i++)
			for (int j = 0; j < extent; j++)
				for (int k = 0; k < extent; k++)
					if (m_distanceToCharacter[j][k] > (m_distanceToCharacter[i][k] + m_distanceToCharacter[j][i]))
						// Minimize route.
						m_distanceToCharacter[j][k] = m_distanceToCharacter[i][k] + m_distanceToCharacter[j][i];
	}

	long long minimumCost(const string& source, const string& target, const vector<char>& original, const vector<char>& changed, const vector<int>& cost) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup cost table.
		floydWarshallAlgorithm(original, changed, cost);

		// Find minimum cost.
		long long minimumCost = 0;
		const int n = min(source.size(), target.size());
		for (int i = 0; i < n; i++) {
			const int
				row = source[i] - 'a',
				col = target[i] - 'a';

			// Invalid path check.
			if (m_distanceToCharacter[row][col] > 10e6)
				return -1;

			// Add to cost.
			minimumCost += m_distanceToCharacter[row][col];
		}
		return minimumCost;
	}
};