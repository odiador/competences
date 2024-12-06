public class ContadorDesordenados {
    public static void main(String[] args) {
        int[] alturas = {28, 30, -29, 28};
        int n = alturas.length;
    }

    public static int contarInversiones(int[] alturas) {
        return mergeSortContar(alturas, 0, alturas.length - 1);
    }

    private static int mergeSortContar(int[] arr, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = (left + right) / 2;
        int inversions = 0;

        // Contamos inversiones en la mitad izquierda, mitad derecha y en el merge
        inversions += mergeSortContar(arr, left, mid);
        inversions += mergeSortContar(arr, mid + 1, right);
        inversions += mergeYContar(arr, left, mid, right);

        return inversions;
    }

    private static int mergeYContar(int[] arr, int left, int mid, int right) {
        int[] leftArray = new int[mid - left + 1];
        int[] rightArray = new int[right - mid];

        for (int i = 0; i < leftArray.length; i++) {
            leftArray[i] = arr[left + i];
        }
        for (int i = 0; i < rightArray.length; i++) {
            rightArray[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = left, inversions = 0;

        // Mezclamos ambas mitades y contamos las inversiones
        while (i < leftArray.length && j < rightArray.length) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k++] = leftArray[i++];
            } else {
                arr[k++] = rightArray[j++];
                inversions += (mid + 1) - (left + i); // Número de elementos restantes en leftArray
            }
        }

        // Copiamos los elementos restantes
        while (i < leftArray.length) {
            arr[k++] = leftArray[i++];
        }
        while (j < rightArray.length) {
            arr[k++] = rightArray[j++];
        }

        return inversions;
    }
}
