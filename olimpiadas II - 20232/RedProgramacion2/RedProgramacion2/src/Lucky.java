import java.util.Scanner;

public class Lucky {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		if (contains7(num)) {
			if (num % 7 == 0) {
				System.out.println(3);
			} else {
				System.out.println(2);
			}

		} else if (num % 7 == 0) {
			System.out.println(1);
		} else {
			System.out.println(0);
		}
		sc.close();
	}

	private static boolean contains7(int num) {
		String numString = num + "";
		for (int i = 0; i < numString.length(); i++)
			if (numString.charAt(i) == '7')
				return true;
		return false;
	}
}
