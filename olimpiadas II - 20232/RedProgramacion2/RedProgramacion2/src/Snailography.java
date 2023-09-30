import java.util.Scanner;

public class Snailography {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String cad = sc.next();
		char[][] matriz = new char[n][n];
		int mitad = n / 2;
		StringBuilder result = new StringBuilder();
		matriz[mitad][mitad] = cad.charAt(0);
		{
			int i = mitad;
			int j = mitad;
			int x = 1;
			int cant = 1;
			try {
				while (i >= 0 && j >= 0) {
					int cantMoves = cant;
					while (cantMoves > 0) {
						i--;
						matriz[i][j] = getChar(cad, x);
						x++;
						cantMoves--;
					}
					cantMoves = cant;
					while (cantMoves > 0) {
						j++;
						matriz[i][j] = getChar(cad, x);
						x++;
						cantMoves--;
					}
					cant++;
					cantMoves = cant;
					while (cantMoves > 0) {
						i++;
						matriz[i][j] = getChar(cad, x);
						x++;
						cantMoves--;
					}
					cantMoves = cant;
					while (cantMoves > 0) {
						j--;
						matriz[i][j] = getChar(cad, x);
						x++;
						cantMoves--;
					}
					cant++;

				}
			} catch (Exception e) {
			}
		}
		for (int i = 0; i < matriz.length; i++) {
			for (int j = 0; j < matriz[i].length; j++) {

				if (matriz[i][j] != '#')
					result.append(matriz[i][j]);
			}
		}
		System.out.println(result.toString());
		sc.close();
	}

	private static char getChar(String cad, int x) {
		return x >= cad.length() ? '#' : cad.charAt(x);
	}

}
