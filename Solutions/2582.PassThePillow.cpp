class Solution {
public:
	int passThePillow(int n, int time) {
		const int len = n - 1, mod = len * 2;
		return (time % mod >= len ? (len - (time % len)) : (time % len)) + 1;
	}
};