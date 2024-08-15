class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

        // Do the math.
        int fives = 0, tens = 0, twenties = 0;
        for (const int price : bills) {
            // Find the failing cas.e
            switch (price) {
                case 5: {
                    fives++;
                } break;
                case 10: {
                    tens++;
                    if (fives >= 1) {
                        fives -= 1;
                    } else {
                        return false;
                    }
                } break;
                case 20: {
                    twenties++;
                    if (tens >= 1 && fives >= 1) {
                        tens -= 1;
                        fives -= 1;
                    } else if (fives >= 3) {
                        fives -= 3;
                    } else {
                        return false;
                    }
                } break;
            }
        }
        return true;
    }
};