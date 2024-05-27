import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
	private static int T;
	private static int[] data;

	private static String input = 
		"7 11\r\n" + 
		"0 1 32\r\n" + 
		"0 2 31\r\n" + 
		"0 5 60\r\n" + 
		"0 6 51\r\n" + 
		"1 2 21\r\n" + 
		"2 4 46\r\n" + 
		"2 6 25\r\n" + 
		"3 4 34\r\n" + 
		"4 6 51\r\n" + 
		"5 3 18\r\n" + 
		"5 4 40";

	static int[] nodes;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		
		for(int t = 1; t <= T; t++) {
			int ans = 0;
			
			int N = sc.nextInt();
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
