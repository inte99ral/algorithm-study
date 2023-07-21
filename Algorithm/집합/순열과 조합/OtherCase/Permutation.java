package 집합.순열과조합;
import java.util.Arrays;

import java.util.Arrays;
import java.util.Scanner;

public class Permutation {
	static int N, R;
	static int[] data;
	static int[] sel;
	static boolean[] visited;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = 4;
		R = 2;
		data = new int[] {1, 2, 3, 4};
		sel = new int[R];
		visited = new boolean[N];
		
//		print("루프 - 무조건 2개 뽑기");
//		perm1();
		
//		print("루프 + 재귀");
//		perm2(0);
		
		print("비트마스킹");
		perm3(0, 0);
		
//		print("스왑");
//		perm4(0);
	}
	
	private static void perm1() {
		for(int i = 0; i < N; i++) {
			sel[0] = data[i];
			
			for(int j = 0; j < N; j++) {
				if(i == j) continue; // i 에서 이미 선택한 것
				
				sel[1] = data[j];
				System.out.println(Arrays.toString(sel));
			}
		}
	}
	
	private static void perm2(int cnt) {
		// 다 뽑았다
		if(cnt == R) {
			System.out.println(Arrays.toString(sel));
			return;
		}
		
		for(int i = 0; i < N; i++) {
			if(visited[i]) continue;
			
			sel[cnt] = data[i];
			visited[i] = true; // 그거 뽑았다
			
			perm2(cnt + 1);
			
			visited[i] = false; // 안뽑는 경우의 수 계속 진행
		}
	}
	
	private static void perm3(int cnt, int visited) {
		if(cnt == R) {
			System.out.println(Arrays.toString(sel));
			return;
		}
		
		for(int i = 0; i < N; i++) {
			if((visited & 1 << i) > 0) continue;
			
			sel[cnt] = data[i];
			perm3(cnt + 1, visited | 1 << i);
		}
	}
	
	private static void print(String msg) {
		System.out.println("-----------------");
		System.out.println(msg);
		System.out.println("-----------------");
	}
}



//public class Permutation {
//	static int[] data;
//	
//	public static void main(String[] args) {
//		data = new int[] { 0, 1, 2, 3 };
//		
//		perm(data, 0, 4, 2);
//		
//	}
//	
//	static void swap(int[] tArr, int x, int y) {
//		int temp = tArr[x];
//		tArr[x] = tArr[y];
//		tArr[y] = temp;
//	}
//	
//	static void perm(int[] tArr, int depth, int n, int r) {
//		// 다 골랐으면
//		if(depth == r) {
//			System.out.println(Arrays.toString(tArr));
//			return;
//		}
//		 
//		for(int i = depth; i < n; i++) {
//			swap(tArr, depth, i);
//			perm(tArr, depth + 1, n, r);
//			swap(tArr, depth, i);
//		}
//	}
	
//	static void perm_bitmasking(int idx) {
//		if(idx == N) {
//			System.out.println(Arrays.toString(data));
//			return;
//		}
//		for(int i = idx; i < N; i++) {
//			swap(i, idx);
//			//perm(idx + 1);
//			swap(i, idx);
//		}
//	}
	
//	static void perm_visited(int idx, int visited) {
//		System.out.println(idx);
//		if(idx == N) {
//			System.out.println(Arrays.toString(data));
//			return;
//		}
//		for(int i = idx; i < N; i++) {
//			swap(i, idx);
//			perm(idx + 1);
//			swap(i, idx);
//		}
//	}
//}
