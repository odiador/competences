import java.util.Scanner;

public class Problem494 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s;
		while (sc.hasNextLine()) {
			s = sc.nextLine();
			int words = 0;
			String[] split = s.split(" ");
			for (String pt : split) {
				if (isAlphabet(pt)) {
					words++;
				}
			}
			System.out.println(words);
		}
		sc.close();
	}

	private static boolean isAlphabet(String pt) {
		final int length = pt.length();
		for (int i = 0; i < length; i++) {
			char c = pt.charAt(i);
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
				return true;
			}
		}
		return false;
	}
}
