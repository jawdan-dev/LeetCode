class Solution {
public:
    std::vector<int> getVersionValues(const string& versionString) {
        // Get version list.
        std::vector<int> result;
        int currentValue = 0;
        for (int i = 0; i < versionString.size(); i++) {
            if (versionString[i] == '.') {
                result.emplace_back(currentValue);
                currentValue = 0;
            } else {
                currentValue *= 10;
                currentValue += versionString[i] - '0';
            }
        }
        if (currentValue) result.emplace_back(currentValue);

        return result;
    }

    int compareVersion(string version1, string version2) {
        // Get version lists.
        vector<int>
            v1 = getVersionValues(version1),
            v2 = getVersionValues(version2);

        for (int i = 0; i < v1.size() || i < v2.size(); i++) {
            if (v1.size() <= i) {
                if (v2[i] > 0) return -1;
            } else if (v2.size() <= i) {
                if (v1[i] > 0) return 1;
            } else {
                if (v1[i] < v2[i]) return -1;
                else if (v1[i] > v2[i]) return 1;
            }
        }
        return 0;
    }
};