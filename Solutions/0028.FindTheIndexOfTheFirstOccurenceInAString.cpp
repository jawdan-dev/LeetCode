class Solution {
public:
	int strStr(string haystack, string needle) {
		const int needleSize = needle.size();
		const int haystackLast = haystack.size() - needleSize;
		for (int i = 0; i <= haystackLast; i++) {
			int j = 0;
			for (; j < needleSize && needle[j] == haystack[i + j]; j++);
			if (j == needleSize) return i;
		}
		return -1;
	}
};