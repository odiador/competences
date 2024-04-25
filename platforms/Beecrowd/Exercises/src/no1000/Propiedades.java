package no1000;

import java.util.Scanner;

public class Propiedades {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			while (sc.hasNext()) {
				String string = sc.next();
				System.err.println(string + ":\t" + getResult(string.charAt(0)) + " \t" + getResult(string.charAt(1))
						+ "\t" + getResult(string.charAt(2)));
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String getResult(char ch) {
		switch (ch) {
		case '0' -> {
			return "---";
		}
		case '1' -> {
			return "--x";
		}
		case '2' -> {
			return "-w-";
		}
		case '3' -> {
			return "-wx";
		}
		case '4' -> {
			return "r--";
		}
		case '5' -> {
			return "r-x";
		}
		case '6' -> {
			return "rw-";
		}
		case '7' -> {
			return "rwx";
		}
		}
		return null;
	}
}
