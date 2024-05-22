class Solution {
public:
	string* m_string;
	int m_n;
	vector<string> m_workingSet;
	vector<vector<string>> m_sets;

	const bool isPalindrome(int start, int end) {
		// Check if not palindrome by counter-evidence.
		while (start < end) {
			// Check counter evidence.
			if ((*m_string)[start] != (*m_string)[end]) return false;

			// Move pointers.
			start++;
			end--;
		}

		// Is a palindrome.
		return true;
	}

	void getPalindromeSets(const int index) {
		if (index >= m_n) {
			// Add partitions to total sets.
			m_sets.push_back(m_workingSet);
			return;
		}

		for (int i = index; i < m_n; i++) {
			if (!isPalindrome(index, i)) continue;

			// Add palindrome to working set.
			m_workingSet.push_back(m_string->substr(index, (i - index) + 1));
			// Work on next partition.
			getPalindromeSets(i + 1);
			// Reset state.
			m_workingSet.pop_back();
		}
	}

	vector<vector<string>> partition(string s) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Initialize calculation variables.
		m_string = &s;
		m_n = m_string->size();

		// Calculate sets.
		getPalindromeSets(0);
		return m_sets;
	}
};