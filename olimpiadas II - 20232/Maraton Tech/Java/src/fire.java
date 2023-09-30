	import java.util.Scanner;
	
	public class fire {
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			while (sc.hasNextLine()) {
				String[] info = sc.nextLine().split(" ");
				int people = Integer.parseInt(info[0]);
				int stock = Integer.parseInt(info[1]);
				int counter = 0;
				boolean[] actions = new boolean[8];
				for (int i = 0; i < people; i++) {
					info = sc.nextLine().split(" ");
					int x = Integer.parseInt(info[0]);
					int y = Integer.parseInt(info[1]);
					if (!actions[0] && x == 0 && y > 0) {
						actions[0] = true;
					} else if (!actions[1] && x > 0 && x == y) {
						actions[1] = true;
					} else if (!actions[2] && x > 0 && y == 0) {
						actions[2] = true;
					} else if (!actions[3] && x > 0 && y == -x) {
						actions[3] = true;
					} else if (!actions[4] && x == 0 && y < 0) {
						actions[4] = true;
					} else if (!actions[5] && x < 0 && y == x) {
						actions[5] = true;
					} else if (!actions[6] && x < 0 && y == 0) {
						actions[6] = true;
					} else if (!actions[7] && x < 0 && y == -x) {
						actions[7] = true;
					} else
						continue;
					counter++;
				}
				System.out.println(counter > stock ? "WAIT" : "ATTACK");
			}
			sc.close();
		}
	}
