class Solution {
public:
	long long maximumHappinessSum(vector<int>& happiness, int k) {
		sort(happiness.begin(), happiness.end());

		long long sum = 0;
		long long offset = 0;
		while (k > 0 && happiness.size() > 0) {
			if (offset < happiness.back())
				sum += happiness.back() - offset;
			happiness.pop_back();
			k--;
			offset++;
		}
		return sum;
	}
};