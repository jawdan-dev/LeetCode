class Solution {
public:
    static const int getRomanValue(const char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    int romanToInt(string s) {
        // Create pair table.
        static const struct { char key[3]; int value; } pairTable[] = {
            { "IV", 4 }, { "IX", 9 }, 
            { "XL", 40 }, { "XC", 90 }, 
            { "CD", 400 }, { "CM", 900 }, 
        };

        // Result storage.
        int value = 0;

        // Handle pairs.
        for (int i = 1; i < s.size();) {
            // Find pair.
            bool found = false;
            for (int j = 0; j < sizeof(pairTable) / sizeof(*pairTable); j++) {
                // Check for pair.
                if (s[i - 1] != pairTable[j].key[0] || s[i] != pairTable[j].key[1]) continue;

                // Add value.
                value += pairTable[j].value;
                found = true;
                break;
            }

            // Handle if found.
            if (found) s.erase(i-1, 2);
            else i++;
        }

        // Handle simple values;
        for (int i = 0; i < s.size(); i++) {
            value += getRomanValue(s[i]);
        }

        // Return result.
        return value;
    }
};