class Solution {
public:
	// Lookup fun.
	static constexpr string
		m_digits[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine " },
		m_teens[] = { "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " },
		m_tens[] = { "", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };


	static inline const string getNumberString(const int value, const int exponent) {
		// Early exit.
		if (value <= 0) return "";

		// String storage.
		string numberString = "";

		// Process hundredth place.
		const int hundreds = value / 100;
		if (hundreds > 0)
			numberString += m_digits[hundreds] + "Hundred ";

		// Process tens place.
		const int tens = (value % 100) / 10;
		const int digits = (value % 10);
		if (tens == 1) {
			// The annoying specific ones.
			numberString += m_teens[digits];
		} else {
			// Standard easy ones.
			numberString += m_tens[tens];
			numberString += m_digits[digits];
		}

		// Add exponent based word.
		switch (exponent) {
			case 1: numberString += "Thousand "; break;
			case 2: numberString += "Million "; break;
			case 3: numberString += "Billion "; break;
		}

		return numberString;
	}

	string numberToWords(int num) {
		// Speed thingies.
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		// Early exit case.
		if (num == 0) return "Zero";

		// Get numbers to be processed.
		stack<int> toBeProcessed;
		while (num > 0) {
			toBeProcessed.push(num % 1000);
			num /= 1000;
		}

		// Get number string.
		string numberString = "";
		while (!toBeProcessed.empty()) {
			// Get from top of stack.
			const int processingTarget = toBeProcessed.top();
			toBeProcessed.pop();

			// Add to number string.
			numberString += getNumberString(processingTarget, toBeProcessed.size());
		}

		// Trim trailing space.
		numberString.erase(numberString.end() - 1, numberString.end());

		// Return final string.
		return numberString;
	}
};