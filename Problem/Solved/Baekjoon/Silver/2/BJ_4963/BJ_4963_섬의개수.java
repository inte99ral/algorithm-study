package BJ.Silver.S2;
// 

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_4963_섬의개수 {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static int w;
	private static int h;
	private static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
	private static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
	private static int[][] matrix;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		
		st = new StringTokenizer(br.readLine());
		
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		int result = 0;
		
		while((w != 0) && (h != 0)) {
			matrix = new int[h][w];
			for(int y = 0; y < h; y++) {
				st = new StringTokenizer(br.readLine());
				for(int x = 0; x < w; x++) {
					matrix[y][x] = st.nextToken().equals("1")? 1 : 0;
				}
			}
			
			for(int y = 0; y < h; y++) {
				for(int x = 0; x < w; x++) {
					if(matrix[y][x] == 1) {
						result++;
						connectionCheck(y, x);
					}
				}
			}
			
			// output
			System.out.println(result);
			
			// init
			st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			result = 0;
		}
		
		return;
	}
	
	public static void connectionCheck(int y, int x) {
		for(int i = 0; i < 8; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if((0 <= Y) && (Y < h) && (0 <= X) && (X < w) && (matrix[Y][X] == 1)) {
				matrix[Y][X] = 2;
				connectionCheck(Y, X);
			}
		}
	}
}
