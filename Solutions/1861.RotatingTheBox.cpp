class Solution {
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		const int n = box[0].size(), m = box.size();

		int i, j, k;
		for (j = 0; j < m; j++) {
			for (i = n - 1; i >= 0; i--) {
				if (box[j][i] != '#') continue;

				k = i + 1;
				while (k < n && box[j][k] == '.') k++;
				k--;

				if (k == i) continue;

				box[j][i] = '.';
				box[j][k] = '#';
			}
		}

		vector<vector<char>> newBox(n, vector<char>(m, 'x'));
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				newBox[i][j] = box[(m - j) - 1][i];

		return newBox;
	}
};