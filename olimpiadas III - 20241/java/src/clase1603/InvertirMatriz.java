package clase1603;

import org.junit.Test;

public class InvertirMatriz {
	@Test
	public void test() {
		int[][] matriz = { { 1, 2, 3 }, { 4, 5, 6 } };

		for (int i = 0; i < matriz.length; i++) {
			for (int j = 0; j < matriz[i].length; j++) {
				System.out.print(matriz[i][j] + " ");
			}
			System.out.println("\n");
		}
		int[][] nueva = girarMatriz(matriz, 1);
		for (int i = 0; i < nueva.length; i++) {
			for (int j = 0; j < nueva[i].length; j++) {
				System.out.print(nueva[i][j] + " ");
			}
			System.out.println("\n");
		}
	}

	public static int[][] girarMatriz(int[][] matriz, int n) {
		if (n == 0)
			return matriz;
		int[][] nueva = new int[matriz[0].length][matriz.length];
		if (n > 0) {
			girarMatrizDere(nueva, matriz, 0, 0);
			return girarMatriz(nueva, n - 1);
		} else {
			girarMatrizIzq(nueva, matriz, 0, 0);
			return girarMatriz(nueva, n + 1);
		}
	}

	private static void girarMatrizDere(int[][] save, int[][] matriz, int i, int j) {
		if (i == matriz.length)
			return;
		if (j == matriz[0].length) {
			girarMatrizDere(save, matriz, i + 1, 0);
			return;
		}
		save[j][matriz.length - 1 - i] = matriz[i][j];
		girarMatrizDere(save, matriz, i, j + 1);
	}

	private static void girarMatrizIzq(int[][] save, int[][] matriz, int i, int j) {
		if (i == matriz.length)
			return;
		if (j == matriz[0].length) {
			girarMatrizIzq(save, matriz, i + 1, 0);
			return;
		}
		save[matriz[0].length - 1 - j][i] = matriz[i][j];
		girarMatrizIzq(save, matriz, i, j + 1);
	}
}
