import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
    int N;
    int M;
    int[] iArr;

    {
      Scanner sc = new Scanner(new FileInputStream("question/input.txt"));
      N = sc.nextInt();
      M = sc.nextInt();
      sc.close();
    }

		iArr = new int[N];
		for(int i = 0; i < N; i++) iArr[i] = i + 1;
		perm(iArr, 0, N, M);
	}
	
	public static void perm(int[] input, int depth, int n, int r) {
    if(depth == r) {
			System.out.println(Arrays.toString(Arrays.copyOfRange(input, 0, r)).replaceAll("[\\[\\,\\]]", ""));
			return;
		}
		for(int i = 0; i < n; i++) {
			swap(input, depth, i);
			perm(input, depth + 1, n, r);
			swap(input, depth, i);
		}
	}
	
	public static void swap(int[] input, int x, int y) {
		int temp = input[x];
		input[x] = input[y];
		input[y] = temp;
	}
}
