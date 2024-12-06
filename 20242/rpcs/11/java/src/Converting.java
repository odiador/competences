import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Converting {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		Map<Character, Integer> map = new HashMap<>();

		map.put('I', 1);
		map.put('V', 5);
		map.put('X', 10);
		map.put('L', 50);
		map.put('C', 100);
		map.put('D', 500);
		map.put('M', 1000);

		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = obtenerNumRomano(map, sc.next());
		}
		for (int v : r)
			System.out.println(v);
		sc.close();
	}

	private static int obtenerNumRomano(Map<Character, Integer> map, String num) {
		int removingFrom = map.get(num.charAt(num.length() - 1));
		int sum = removingFrom;
		for (int i = num.length() - 2; i >= 0; i--) {
			char ch = num.charAt(i);
			int value = map.get(ch);
			if (value >= removingFrom) {
				sum += value;
				removingFrom = value;
			} else {
				sum -= value;
			}
		}
		return sum;
	}
}
