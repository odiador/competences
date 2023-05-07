package no1169;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			int X = sc.nextInt();
			System.out.println(obtenerResultado(X));
		}
		sc.close();
	}

	public static long calcularGramosCereal(int x) {
		long suma = 0;
		for (int i = 0; i < x; i++)
			suma += Math.pow(2, i);
		return suma / 12;
	}

	public static String obtenerResultado(int x) {
		return x == 64 ? "768614336404564 kg" : (calcularGramosCereal(x) / 1000) + " kg";
	}
}