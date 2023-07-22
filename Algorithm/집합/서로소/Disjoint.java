package 집합.서로소;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Disjoint {
	private static int T;
	private static int[] data;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		
		for(int t = 1; t <= T; t++) {
			int ans = 0;
			
			int N = sc.nextInt(),
			int M = sc.nextInt();
			
			data = new int[N + 1];
			
			// makeSet
			for(int i = 1; i <= N; i++) {
				data[i] = i;
			}
			
			for(int i = 0; i < M; i++) {
				unionSet(sc.nextInt(), sc.nextInt());
			}
			
			for(int i = 1; i <= N; i++) {
				if(data[i] == i) ans ++;
			}
			
			System.out.println("#" + t + " " + ans);
		}
	}
	
	public static void unionSet(int x, int y) {
		int px = findSet(x);
		int py = findSet(y);
		data[py] = px;
	}

	public static int findSet(int x) {
		if(x == data[x]) { 
			return x;
		}
		return data[x] = findSet(data[x]);
	}
}
