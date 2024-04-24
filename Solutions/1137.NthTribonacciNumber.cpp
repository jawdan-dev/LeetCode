class Solution {
public:
    int tribonacci(int n) {
        // Circular calculation storage.
        constexpr int tableSize = 4;
        //                       a  b  c  t
        int table[tableSize] = { 0, 1, 1, 2 };
        // Helpful macros.
#       define a 0
#       define b 1
#       define c 2
#       define t 3

        // Early exit.
        if (n < tableSize)
            return table[n];

        // Fill data.
        for (int i = 3; i <= n; i++) {
            table[t] = table[a];
            table[a] = table[b];
            table[b] = table[c];
            table[c] = table[a] + table[b] + table[t];
        }

        // Return table data.
        return table[c];
    }
};