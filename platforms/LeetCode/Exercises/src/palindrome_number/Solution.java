package palindrome_number;

public class Solution {
	public boolean isPalindrome(int x) {
		String string = String.valueOf(x);
		return string.equals(new StringBuilder(string).reverse().toString());
	}

}
