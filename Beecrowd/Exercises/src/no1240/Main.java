package no1240;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			System.out.println(retorno(A, B));
		}
		sc.close();
	}

	public static boolean obtenerBinA(int A, int B) {
		return Integer.toString(A).endsWith(Integer.toString(B));
	}

	public static String retorno(int A, int B) {
		return obtenerBinA(A, B) ? "encaixa" : "nao encaixa";
	}
}
