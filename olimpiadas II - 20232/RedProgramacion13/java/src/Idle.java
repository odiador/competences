import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Idle {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int cantHilos = sc.nextInt();

		ArrayList<Integer> list = new ArrayList<Integer>();
		Integer arr[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			if (i < cantHilos)
				list.add(arr[i]);
		}
		if (n == 1) {
			System.out.println(arr[0]);
			sc.close();
			return;
		}
		if (cantHilos == 1) {
			int dif = 0;
			for (Integer num : arr) {
				if (num > dif)
					dif = num;
			}
			System.out.println(dif);
			sc.close();
			return;
		}
		Collections.sort(list);
		int dif = arr[1] - arr[0];
		for (int i = 0; i < n - cantHilos; i++) {
			int foundDif = findMaxDif(list, cantHilos);
			if (foundDif > dif)
				dif = foundDif;
			list.add(list.get(i) + arr[i + cantHilos]);
		}
		System.out.println(dif);
		sc.close();
	}

	private static int findMaxDif(ArrayList<Integer> list, int cantHilos) {
		int size = list.size();
		int dif = 0;
		for (int i = size - cantHilos; i < size - 1; i++) {
			int newDif = Math.abs(list.get(i) - list.get(i + 1));
			if (newDif > dif)
				dif = newDif;
		}
		return dif;

	}
}
