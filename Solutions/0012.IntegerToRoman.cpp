class Solution {
public:
	string tryRoman(
		int& num,
		const int smallVal, const char smallChar, // Factors of 1
		const int mediumVal, const char mediumChar, // Factors of 5
		const int largeVal, const char largeChar // Factors of 10
	) {
		// String storage.
		string roman = "";

		// Get large + small counts.
		const int largeCount = num / largeVal;
		int smallCount = (num % largeVal) / smallVal;

		for (int i = 0; i < largeCount; i++, num -= largeVal) roman += largeChar;
		switch (smallCount) {
			default: {
				// Check for past halfway point.
				if (smallCount >= 5) {
					// Handle halfway point.
					roman += mediumChar;
					smallCount -= 5;
					num -= mediumVal;
				}

				// Append small chars.
				for (int i = 0; i < smallCount; i++) roman += smallChar; break;
			}
			case 4: {
				// Handle IV case.
				roman += smallChar;
				roman += mediumChar;
			} break;
			case 9: {
				// Handle IX case.
				roman += smallChar;
				roman += largeChar;
			} break;
		}

		// Update num.
		num -= smallVal * smallCount;

		return roman;
	}

	string intToRoman(int num) {
		string roman = "";

		// Generate roman string for each stage.
		roman += tryRoman(num, 100, 'C', 500, 'D', 1000, 'M');
		roman += tryRoman(num, 10, 'X', 50, 'L', 100, 'C');
		roman += tryRoman(num, 1, 'I', 5, 'V', 10, 'X');

		return roman;
	}
};