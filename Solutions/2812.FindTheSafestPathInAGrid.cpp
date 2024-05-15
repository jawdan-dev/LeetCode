class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Variables.
        const int n = grid.size();
        const auto inBounds = [n](const int x, const int y) {
            return x >= 0 && y >= 0 && x < n && y < n;
        };

        static constexpr int checks[][2] = {
            { -1, 0 }, { 1, 0 },
            { 0, -1 }, { 0, 1 },
        };

        // Init tile scores.     
        deque<tuple<int, int, int>> tileQueue;   
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1) {
                    grid[j][i] = 0;
                    tileQueue.emplace_back(i, j, grid[j][i]);
                } else {
                    grid[j][i] = -1;
                }
            }
        }

        // Generate scores.
        while (!tileQueue.empty()) {
            const auto [x, y, score] = tileQueue.front();
            tileQueue.pop_front();

            for (int k = 0; k < sizeof(checks) / sizeof(*checks); k++) {
                const int cx = x + checks[k][0], cy = y + checks[k][1];

                if (inBounds(cx, cy) && grid[cy][cx] == -1) { 
                    tileQueue.emplace_back(cx, cy, score + 1);
                    grid[cy][cx] = score + 1;
                }
            }
        }

        // Path finding.
        int minSafety = grid[0][0];
        tileQueue.emplace_back(0, 0, minSafety);
        while (!tileQueue.empty()) {
            const auto [ x, y, safety ] = tileQueue.front();
            tileQueue.pop_front();

            minSafety = min(minSafety, safety);

            if (x == n - 1 && y == n - 1) break;

            for (int k = 0; k < sizeof(checks) / sizeof(*checks); k++) {
                const int cx = x + checks[k][0], cy = y + checks[k][1];
                if (inBounds(cx, cy) && grid[cy][cx] >= 0) {
                    const int cScore = grid[cy][cx];
                    if (cScore >= minSafety) {
                        tileQueue.emplace_front(cx, cy, cScore);
                    } else {
                        tileQueue.emplace_back(cx, cy, cScore);
                    }
                    grid[cy][cx] = -1;
                }
            }
        }

        return minSafety;
    }
};