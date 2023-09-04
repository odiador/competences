public class NumMayorArr {

	/**
	 * Nuestro primer metodo divide y venceras 🥰
	 * 
	 * @param arr
	 * @return
	 */
	public static int numMayorDivideyVenceras(int[] arr) {
		if (arr.length == 2)
			return arr[0] > arr[1] ? arr[0] : arr[1];

		if (arr.length == 1) {
			return arr[0];
		}
		int[] primeraMitad;
		int[] segundaMitad;

		if (arr.length % 2 == 1) {
			primeraMitad = new int[(arr.length / 2)];
			System.arraycopy(arr, 0, primeraMitad, 0, (arr.length / 2));
			if (((arr.length) / 2) % 2 == 0) {
				segundaMitad = new int[(arr.length / 2) + 2];
				System.arraycopy(arr, arr.length / 2, segundaMitad, 0, (arr.length / 2) + 1);
				segundaMitad[segundaMitad.length - 2] = arr[arr.length - 1];
				segundaMitad[segundaMitad.length - 1] = Integer.MIN_VALUE;

			} else {
				segundaMitad = new int[(arr.length / 2) + 1];
				System.arraycopy(arr, arr.length / 2, segundaMitad, 0, (arr.length / 2) + 1);
				segundaMitad[segundaMitad.length - 1] = arr[arr.length - 1];

			}
		} else {
			primeraMitad = new int[arr.length / 2];
			segundaMitad = new int[arr.length / 2];
			System.arraycopy(arr, 0, primeraMitad, 0, arr.length / 2);
			System.arraycopy(arr, arr.length / 2, segundaMitad, 0, arr.length / 2);
		}
		int[] arrFinal = new int[] { numMayorDivideyVenceras(primeraMitad), numMayorDivideyVenceras(segundaMitad) };
		return numMayorDivideyVenceras(arrFinal);
	}

	public static void main(String[] args) {
		int[] arr = { 5, 9, 10, 3, 20, 10, 1, 5, 8, 3, 30 };
		int mayorDivideyVenceras = numMayorDivideyVenceras(arr);
		System.out.println(mayorDivideyVenceras);
	}
}
