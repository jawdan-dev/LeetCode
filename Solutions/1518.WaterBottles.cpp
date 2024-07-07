class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		// NOTE: Going for a O(1) solution here.

		// 9 + 3(0) + 1(0)
		// so 9 & 3 => 4 total extra

		// 15(12) + 3(6) + 1(2)
		// so 15 & 4 => 4 total extra.

		// We can ignore the first term for now as thats equivalent to numBottles.

		//  8x + 3y = 3
		//  9x + 3y = 4
		// 10x + 3y = 4
		// 11x + 3y = 5
		// 12x + 3y = 5
		// 13x + 3y = 6
		//            ^ period of 2.

		// 15x + 4y = 4
		// 16x + 4y = 5
		// 17x + 4y = 5
		// 18x + 4y = 5
		// 19x + 4y = 6
		// 20x + 4y = 6
		// 21x + 4y = 6
		// 22x + 4y = 7
		//            ^ period of 3.

		// period = numExchange - 1.
		const int period = numExchange - 1;

		//  9x +  2y = 8
		//  9x +  3y = 4
		//  9x +  4y = 2
		//  9x +  5y = 2
		//  9x +  6y = 1
		//  9x +  7y = 1
		//  9x +  8y = 1
		//  9x +  9y = 1
		//  9x + 10y = 0
		//             ^ I dont get it....

		// 15x +  2y = 14
		// 15x +  3y = 7
		// 15x +  4y = 4
		// 15x +  5y = 3
		// 15x +  6y = 2
		// 15x +  7y = 2
		// 15x +  8y = 2
		// 15x +  9y = 1
		// 15x + 10y = 1
		//             ^ Welp,, inverse power stuff?. 

		// The directly above one looks like ^ 3 -esque progression.
		// The other one is directly the 2^n progression.

		// Oh its the period,, gotcha.
		// so its numBottles ^ (1 / period)?
		// Well,, numBottles / period.

		// Double checking hypothesesis.
		// 15 / 1p = 15 <-- incorrect. (expected 14)
		// 15 / 2p = 7
		// 15 / 3p = 4
		// 15 / 4p = 3
		// 15 / 5p = 3 <-- incorrect. (expected 2)
		// 15 / 6p = 2

		// Based on the first case it needs to be numBottles - 1 in the left.
		// 14 / 1p = 14 :)
		// 14 / 2p = 7
		// 14 / 3p = 4
		// 14 / 4p = 3
		// 14 / 5p = 2 :)
		// 14 / 6p = 2

		// exchangeFactor = numBottles - 1.
		const int exchangeFactor = numBottles - 1;

		// The final equation.
		return numBottles + (exchangeFactor / period);
	}
};