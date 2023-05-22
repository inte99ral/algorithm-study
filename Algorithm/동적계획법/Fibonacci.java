package 동적계획법;

public class Fibonacci {
	public static void main(String[] args) {
		System.out.println(fibonacci(20));
	}
	
	public static int fibonacci(int n) {
		int[] memo = new int[n + 1];
		memo[1] = 1;
		return fibonacciRecur(n, memo);
	}
	
	public static int fibonacciRecur(int n, int[] memo) {
		if(n >= 2 && memo[n] == 0) memo[n] = fibonacciRecur(n - 1, memo) + fibonacciRecur(n - 2, memo);
		return memo[n];
	}
}
