import java.util.Scanner;

public class parindromo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextLine()) {
			String cad = sc.nextLine();
			cad = cad.replace(" ", "");
			System.out.println(getParindromoResult(cad));
		}
		sc.close();
	}

	private static String getParindromoResult(String cad) {
		final int len = cad.length();
		String result = "None";
		for (int i = 0; i < len - 2; i++) {
			for (int j = i + 2; j <= len; j++) {
				final String sub = cad.substring(i, j);
				if (isPalindrome(sub)) {
					if (result.equals("Odd") && sub.length() % 2 == 0)
						return "Both";
					else if (result.equals("Even") && sub.length() % 2 == 1)
						return "Both";
					else if (result.equals("None"))
						result = sub.length() % 2 == 0 ? "Even" : "Odd";
				}
			}
		}
		return result;
	}

	private static boolean isPalindrome(String cad) {
		return new StringBuilder(cad).reverse().toString().equals(cad);
	}
}
