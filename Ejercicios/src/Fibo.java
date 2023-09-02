
public class Fibo {
	public static int fibo(int n) {
		if (n == 0)
			return 1;
		if (n == 1) {
			return n;
		}
		return fibo(n - 1) + fibo(n - 2);
	}

	public static void main(String[] args) {
		for (int i = 0; i < 8; i++) {
			System.out.println(fibo(i));
		}
	}
}
