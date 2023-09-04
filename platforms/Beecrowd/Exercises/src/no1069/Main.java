package no1069;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			String cadena = sc.next();
			int cantidadDiamante = contarDiamante(cadena);
			System.out.println(cantidadDiamante);
		}
		sc.close();
	}

	public static int contarDiamante(String cadena) {
		StringBuilder sb = new StringBuilder(cadena);
		int contador = 0;
		while (true) {
			int indiceMenor = sb.indexOf("<");
			int indiceMayor = sb.indexOf(">");
			if (indiceMenor == -1 || indiceMayor == -1)
				break;
			if (indiceMenor > indiceMayor) {
				sb.deleteCharAt(indiceMayor);
				continue;
			}
			sb.deleteCharAt(indiceMayor);
			indiceMenor = sb.indexOf("<");
			sb.deleteCharAt(indiceMenor);
			contador++;
		}
		return contador;
	}

}
