import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Contest {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		Integer[] arr = new Integer[n];
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
		List<Integer> nums = new ArrayList<>(List.of(arr));
		Collections.sort(nums);
		int count = 0;
		for (int bitmask = (1 << k) - 1; bitmask < 1 << n; bitmask = nextCombination(bitmask)) {
			List<Integer> combination = new ArrayList<>();
			for (int j = 0; j < n; j++) {
				if ((bitmask & (1 << j)) != 0) {
					combination.add(nums.get(j));
				}
			}
			if (combination.size() == k && isNice(combination)) {
				count++;
			}
		}
		System.out.println(count);
		sc.close();
	}

	private static boolean isNice(List<Integer> list) {
		int size = list.size();
		if (size < 3) {
			return true;
		}
		int prevPrev = list.get(0);
		int prev = list.get(1);
		for (int i = 2; i < size; i++) {
			int current = list.get(i);
			if (current > prev + prevPrev) {
				return false;
			}
			prevPrev = prev;
			prev = current;
		}
		return true;
	}

	private static int nextCombination(int x) {
		int y = x & -x, c = x + y;
		return (((x ^ c) >> 2) / y) | c;
	}
}
