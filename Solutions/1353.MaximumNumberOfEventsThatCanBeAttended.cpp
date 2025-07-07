class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		struct {
			bool operator()(vector<int>& a, vector<int>& b) const { return a[0] < b[0]; }
		} sortByStartDay;
		std::sort(events.begin(), events.end(), sortByStartDay);

		std::priority_queue<int, std::vector<int>, std::greater<int>> eventPriority; // Prioritize by end days.

		size_t i = 0;
		int day = 1, daysAttended = 0;
		while (i < events.size() || !eventPriority.empty()) {
			while (!eventPriority.empty() && eventPriority.top() < day)
				eventPriority.pop();

			while (i < events.size() && events[i][0] <= day)
				eventPriority.push(events[i++][1]);

			day++;
			if (eventPriority.empty())
				continue;

			eventPriority.pop();
			daysAttended++;
		}

		return daysAttended;
	}
};