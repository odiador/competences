import java.util.Scanner;

public class Joystick {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String newRecord = sc.next();
		String old = sc.next();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			char charRecord = newRecord.charAt(i);
			char charOld = old.charAt(i);
			if (charRecord == charOld)
				continue;
			int mayor = charRecord > charOld ? charRecord : charOld;
			int menor = mayor == charOld ? charRecord : charOld;

			int normalMove = mayor - menor;
			int fromZMove = 'Z' - mayor + 1 + (menor - 'A');
			if (normalMove < fromZMove)
				sum += normalMove;
			else
				sum += fromZMove;
		}
		System.out.println(sum);
		sc.close();
	}
}
