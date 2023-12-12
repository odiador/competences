import java.util.Scanner;

public class Night {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		int info[] = calcInfo(0, num, 2);
		System.out.println(info[0] + " " + info[1]);
		sc.close();

	}

	private static int[] calcInfo(int info, long num, int i) {
		if (num < 3)
			return new int[] { info, (int) num };
		if (num - (i * (i + 1) / 2) < 0) {
			return calcInfo(info, num, 2);
		}
		return calcInfo(info + 1, num - (i * (i + 1) / 2), i + 1);
	}
}
