class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		// Setup.
		int currentSandwich = 0;
		int remainingPreferences[2] { 0, 0 };
		queue<int> studentQueue;
		for (const int i : students) {
			remainingPreferences[i]++;
			studentQueue.push(i);
		}

		// Simulate students.
		while (currentSandwich < sandwiches.size() && remainingPreferences[sandwiches[currentSandwich]] > 0) {
			const int currentStudent = studentQueue.front();
			if (currentStudent != sandwiches[currentSandwich]) {
				// Put student at back of queue.
				studentQueue.push(currentStudent);
			} else {
				// Student + update sandwich information.
				currentSandwich++;
				remainingPreferences[currentStudent]--;
			}

			// Common pop.
			studentQueue.pop();
		}

		// Return the amount unable to eat.
		return studentQueue.size();
	}
};