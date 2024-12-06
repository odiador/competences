package co.edu.uniquindio.competences.class3108;

import java.util.Arrays;

/**
 * You are given two integer arrays numsl and nums2, sorted in non-decreasing
 * order, and two integers m and n, representing the number of elements in numsl
 * and nums2 respectively. Merge numsl and nums2 into a single array sorted in
 * non-decreasing order. The final sorted array should not be returned by the
 * function, but instead be stored inside the array numsl. To accommodate this,
 * numsl has a length of m + n, where the first m elements denote the elements
 * that should be merged, and the last n elements are set to O and should be
 * ignored. nums2 has a length of n.
 */
public class MergeSortedArray {
	public static void mergeArrays(int[] nums1, int[] nums2, int m, int n) {
		if (n == 0)
			return;
		for (int i = 0; i < n; i++)
			nums1[i + m] = nums2[i];
		Arrays.sort(nums1);
	}

}
