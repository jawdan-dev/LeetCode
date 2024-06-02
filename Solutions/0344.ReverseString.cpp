class Solution {
public:
    void reverseString(vector<char>& s) {
        // Speed thingies.
		ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Swap string.
        char temp;
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
            // Swap.
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }
    }
};