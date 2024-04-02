class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		// Create sorted buffer.
		vector<int> sorted(nums1.size() + nums2.size());
		int i = 0, j = 0, k = 0;

		// Merge sorted arrays.
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j])
				sorted[k++] = nums1[i++];
			else
				sorted[k++] = nums2[j++];
		}

		// Cleanup.
		while (i < nums1.size())
			sorted[k++] = nums1[i++];
		while (j < nums2.size())
			sorted[k++] = nums2[j++];

		// Get middle point.
		const int hs = sorted.size() / 2;

		// Return median.
		return
			(sorted.size() % 2 == 0) ?
			((double)(sorted[hs - 1] + sorted[hs]) / 2.0) :
			sorted[hs];
	}
};