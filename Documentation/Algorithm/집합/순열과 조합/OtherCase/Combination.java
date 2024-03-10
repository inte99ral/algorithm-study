package 집합.순열과조합;
import java.util.Arrays;
import java.util.Scanner;

public class Combination {
	static int N, R;
	static int[] data;
	static int[] sel; // 선택된 것
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = 6;
		R = 3;
		data = new int[] {1, 2, 3, 4, 5, 6};
		sel = new int[R];
		
		print("반복을 이용한 조합 - 무조건 3개 뽑기");
		comb1();
		
//		print("반복 + 재귀 - 무조건 3개 뽑기");
//		comb2(0, 0);
		
//		print("재귀 - 무조건 3개 뽑기");
//		comb3(0, 0);
		
		
		sc.close();
	}
	
	private static void comb1() {
		for(int i = 0; i < N - 2; i++) {
			sel[0] = data[i];
			for(int j = (i + 1); j < N - 1; j++) {
				sel[1] = data[j];
				for(int k = (j + 1); k < N; k++) {
					sel[2] = data[k];
					System.out.println(Arrays.toString(sel));
				}
			}
		}
	}
	
	private static void comb2(int cnt, int start) {
		if(cnt == R) {
			System.out.println(Arrays.toString(sel).replaceAll("[\\,\\[\\]]", ""));
			return;
		}
		for(int i = start; i < N; i++) {
			sel[cnt] = data[i];
			comb2(cnt + 1, i + 1);
		}
	}
	
	private static void comb3(int depth, int idx) {
		if(depth == R) {
			System.out.println(Arrays.toString(sel));
			return;
		}
		if(idx == N) {
			return;
		}
		
		sel[depth] = data[idx];
		comb3(depth + 1, idx + 1);
		comb3(depth, idx + 1);
	}

	
	
	private static void print(String msg) {
		System.out.println("-----------------");
	}
}