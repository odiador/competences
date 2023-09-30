import java.util.Scanner;

public class Problem272 {

	public static String getQuote(boolean start) {
		return start ? "``" : "''";
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean start = true;

		while (sc.hasNextLine()) {
			String line = sc.nextLine();
			int pos = line.indexOf('"');
			StringBuilder result = new StringBuilder();

			while (pos != -1) {
				result.append(line.substring(0, pos));
				result.append(getQuote(start));
				start = !start;
				line = line.substring(pos + 1);
				pos = line.indexOf('"');
			}

			result.append(line);
			System.out.println(result.toString());
		}
		sc.close();
	}

}