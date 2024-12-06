package co.edu.uniquindio.competences;

import java.util.Arrays;

import org.junit.Test;

import co.edu.uniquindio.competences.class3108.MergeSortedArray;

public class Test3108 {
	@Test
	public void test() {
		int[] nums1 = new int[] { 1, 2, 3, 0, 0, 0 };
		int[] nums2 = new int[] { 2, 5, 6 };

		MergeSortedArray.mergeArrays(nums1, nums2, 2, 3);
		System.out.println(Arrays.toString(nums1));
	}
}
