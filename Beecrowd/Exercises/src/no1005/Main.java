package no1005;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double A = sc.nextDouble();
		double B = sc.nextDouble();
		double MEDIA = A * 0.35 * 10 / 11 + B * 0.75 * 10 / 11;
		System.out.println("MEDIA = " + String.format("%.5f", MEDIA).replace(',', '.'));
		sc.close();
	}

}
