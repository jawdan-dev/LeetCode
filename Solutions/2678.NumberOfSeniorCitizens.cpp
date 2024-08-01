class Solution {
public:
    int countSeniors(vector<string>& details) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

        // Okay.
        const int n = details.size();
        int total = 0, age;
        for (int i = 0; i < n; i++) {
            age = ((details[i][11] - '0') * 10) + (details[i][12] - '0');
            total += age > 60;
        }
        return total;
    }
};