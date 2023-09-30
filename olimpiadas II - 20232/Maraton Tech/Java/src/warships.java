import java.util.Scanner;

public class warships {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextLine()) {
			String cad1 = sc.nextLine();
			if (!sc.hasNextLine()) {
				break;
			}
			String cad2 = sc.nextLine();
			final String[] split = cad1.split(" ");
			final String[] split2 = cad2.split(" ");

			String name = split[0];
			String name2 = split2[0];

			int pos = Integer.parseInt(split[1]);
			int pos2 = Integer.parseInt(split2[1]);

			System.out.println(findWinner(name, pos, name2, pos2));
		}
		sc.close();
	}

	private static String findWinner(String name, int pos, String name2, int pos2) {
		if (name.equals(name2)) {
			if (pos > pos2)
				return "Tobby";
			if (pos2 > pos)
				return "Naebbirac";
			return "Draw";
		}

		if (name.equals("Battleships")) {
			if (name2.equals("Destroyers")) {
				if (pos2 >= pos * 2)
					return "Naebbirac";
				return "Tobby";
			}
			if (name2.equals("Cruisers")) {
				if (pos >= pos2 * 2)
					return "Tobby";
				return "Naebbirac";
			}
		}
		if (name.equals("Destroyers")) {
			if (name2.equals("Cruisers")) {
				if (pos2 >= pos * 2)
					return "Naebbirac";
				return "Tobby";
			}
			if (name2.equals("Battleships")) {
				if (pos >= pos2 * 2)
					return "Tobby";
				return "Naebbirac";
			}
		}
		if (name.equals("Cruisers")) {
			if (name2.equals("Battleships")) {
				if (pos2 >= pos * 2)
					return "Naebbirac";
				return "Tobby";
			}
			if (name2.equals("Destroyers")) {
				if (pos >= pos2 * 2)
					return "Tobby";
				return "Naebbirac";
			}
		}
		return "";
	}

}
