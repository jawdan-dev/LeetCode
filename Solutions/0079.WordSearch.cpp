class Solution {
public:
    bool recursiveBacktrackSearch(vector<vector<char>>& board, const char* word, const int x, const int y) {
        // Stop case.
        if (word == nullptr || word[0] == '\0') return true;

        // Make sure its in bounds.
        if (x < 0 || y < 0 || y >= board.size() || x >= board[y].size()) return false;

        // Check for matching character.
        if (board[y][x] != word[0]) return false;

        // Set the character as used.
        board[y][x] = '\0';

        // Recurse to next.
        const int checks[4][2] = {
            { x + 1, y + 0 },
            { x - 1, y + 0 },
            { x + 0, y + 1 },
            { x + 0, y - 1 },
        };
        for (int i = 0; i < sizeof(checks) / sizeof(*checks); i++)
            if (recursiveBacktrackSearch(board, word + 1, checks[i][0], checks[i][1]))
                return true;

        // Reset character.
        board[y][x] = word[0];

        // Word not found.
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Search for word.
        for (int y = 0; y < board.size(); y++)
            for (int x = 0; x < board[y].size(); x++)
                if (recursiveBacktrackSearch(board, word.c_str(), x, y))
                    return true;

        // Word not found.
        return false;
    }
};