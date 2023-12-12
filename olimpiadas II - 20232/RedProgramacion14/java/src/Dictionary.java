import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Dictionary {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		sc.useDelimiter("\n");
		ArrayList<String> diccionario = new ArrayList<String>();
		for (int i = 0; i < x; i++)
			diccionario.add(sc.nextLine());

		Collections.sort(diccionario);
		System.out.println(diccionario);

		String linea;
		for (int i = 0; i < y; i++) {
			linea = sc.nextLine();
			String[] arr = linea.split(" ");
			int cant = hola(diccionario, arr[0], arr[1]);
			System.out.println(cant);
		}
		sc.close();
	}

	private static int hola(ArrayList<String> diccionario, String cad1, String cad2) {
		int i = 0;
		for (; i < diccionario.size(); i++)
			if (diccionario.get(i).compareTo(cad1) > 0)
				break;

		int j = diccionario.size() - 1;
		for (; j >= 0; j--)
			if (diccionario.get(j).compareTo(cad2) > 0)
				break;
		return j - i;
	}
}
