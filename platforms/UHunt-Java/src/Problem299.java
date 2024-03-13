import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Problem299 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nCases = scanner.nextInt();
		while (nCases >= 0) {
			int sum = 0;
			int cant = scanner.nextInt();
			LinkedList<Integer> lst = new LinkedList<Integer>();
			for (int i = 0; i < cant; i++)
				lst.add(scanner.nextInt());
			for (int i = 0; i < cant; i++) {
				Integer min = Collections.min(lst);
				sum += lst.indexOf(min);
				lst.remove(min);
			}
			System.out.println(String.format("Optimal train swapping takes %d swaps.", sum));
			nCases--;

		}
		scanner.close();
	}
}
