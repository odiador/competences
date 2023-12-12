import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Problem1203 {
	private static int multi;

	public static void main(String[] args) {
		HashMap<Integer, Integer> lista = new HashMap<>();
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextLine()) {
			String cad = sc.nextLine();
			if (cad.equals("#"))
				break;
			String[] arr = cad.split(" ");
			lista.put(Integer.parseInt(arr[1]), Integer.parseInt(arr[2]));
		}
		System.out.println(lista);
		int cant = sc.nextInt();
		int aux = cant;
		ArrayList<Entrada> lista1 = new ArrayList<>();

		multi = 1;
		final int tam = lista.size();
		while (aux > 0) {
			lista.entrySet().forEach((Entry<Integer, Integer> entry) -> {
				int key = entry.getKey();
				int value = entry.getValue();
				lista1.add(new Entrada(key, value * multi));
			});
			aux -= tam;
			multi++;
		}
		Collections.sort(lista1);

		for (int i = 0; i < cant; i++)
			System.out.println(lista1.get(i).key);

		sc.close();
	}

	private static class Entrada implements Comparable<Entrada> {
		private Integer key;
		private Integer value;

		public Entrada(Integer key, Integer value) {
			this.key = key;
			this.value = value;
		}

		@Override
		public int compareTo(Entrada o) {
			int resta = value - o.value;
			if (resta == 0)
				return key - o.key;
			return resta;
		}

	}
}
