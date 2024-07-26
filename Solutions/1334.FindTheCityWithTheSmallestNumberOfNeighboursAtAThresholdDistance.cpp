class Solution {
public:
	int m_n, m_distanceThreshold;
	int m_data[100][100];

	void floydWarshallAlgorithmWithThres(const vector<vector<int>>& edges) {
		// Initialize data.
		for (int i = 0; i < sizeof(m_data) / sizeof(*m_data); i++) {
			for (int j = 0; j < sizeof(*m_data) / sizeof(**m_data); j++)
				m_data[i][j] = INT_MAX;
			m_data[i][i] = 0;
		}

		// Add edge paths.
		for (const vector<int>& edge : edges) {
			const int
				from = edge[0],
				to = edge[1],
				distance = edge[2];

			if (distance <= m_distanceThreshold) {
				m_data[from][to] = distance;
				m_data[to][from] = distance;
			}
		}

		// Minimize routes.
		constexpr int maxThreshold = INT_MAX / 2;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_n; j++)
				for (int k = 0; k < m_n; k++)
					if (m_data[i][k] <= (INT_MAX - m_data[j][i]) &&
						m_data[j][k] > (m_data[i][k] + m_data[j][i]))
						// Minimize route.
						m_data[j][k] = m_data[i][k] + m_data[j][i];
	}


	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Setup calculation variables.
		m_n = n;
		m_distanceThreshold = distanceThreshold;

		// Use the Floyd Warshall Algorithm here.
		floydWarshallAlgorithmWithThres(edges);

		int minCount = n, cityIndex = -1;
		for (int i = 0; i < n; i++) {
			// Get count of cities reachable.
			int count = -1;
			for (int j = 0; j < n; j++)
				if (m_data[i][j] <= m_distanceThreshold)
					count++;

			// Check if better.
			if (minCount >= count) {
				minCount = count;
				cityIndex = i;
			}
		}
		return cityIndex;
	}
};