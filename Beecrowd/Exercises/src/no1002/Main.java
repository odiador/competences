package no1002;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double pi = 3.14159d;
		double R = sc.nextDouble();
		String result = String.format("%.4f", pi * R * R).replace(',', '.');
		System.out.println("A=" + result);
		sc.close();
	}

}
