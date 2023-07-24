package BJ.Gold.G1;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ_17472_다리만들기2 {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static int[] dy = {-1, 1, 0, 0};
	private static int[] dx = {0, 0, -1, 1};
	private static int N;
	private static int M;
	private static int cnt;
	private static int[][] matrix;
	private static boolean[][] visited;
	private static int[] island;
	private static int[] p;
	private static PriorityQueue<Edge> q;
	
	private static String input1 =
			"7 8\r\n" + 
			"0 0 0 0 0 0 1 1\r\n" + 
			"1 1 0 0 0 0 1 1\r\n" + 
			"1 1 0 0 0 0 0 0\r\n" + 
			"1 1 0 0 0 1 1 0\r\n" + 
			"0 0 0 0 0 1 1 0\r\n" + 
			"0 0 0 0 0 0 0 0\r\n" + 
			"1 1 1 1 1 1 1 1";
	
	private static String input2 = 
			"7 7\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"0 0 0 0 0 0 0\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1";
	
	public static void main(String[] args) throws Exception {
		init();
		
		islandCheck();
		
		for(int[] iArr : matrix) {
			System.out.println(Arrays.toString(iArr));
		}
		System.out.println();
		
		setEdge();
		
		for(Edge e : q) {
			System.out.println(e.start + " : " + e.end + " : " + e.weight);
		}
		System.out.println();
		
		System.out.println(findMst());
	}
	
	private static void init() throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		//br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(input2.getBytes())));
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		matrix = new int[N][M];
		visited = new boolean[N][M];
		for(int y = 0; y < N; y++) {
			st = new StringTokenizer(br.readLine());
			for(int x = 0; x < M; x++) {
				matrix[y][x] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	private static void islandCheck() {
		cnt = 0;
		for(int y = 0; y < N; y++) {
			for(int x = 0; x < M; x++) {
				if(visited[y][x] || matrix[y][x] == 0) continue;
				islandConnect(y, x, ++cnt);
			}
		}
	}
	
	private static void islandConnect(int y, int x, int num) {
		if(visited[y][x] || matrix[y][x] == 0) return;
		visited[y][x] = true;
		matrix[y][x] = num;
		for(int i = 0;  i < 4 ; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if(Y < 0 || Y >= N || X < 0 || X >= M) continue;
			islandConnect(Y, X, num);
		}
	}
	
	private static class Edge implements Comparable<Edge>{
		public int start;
		public int end;
		public int weight;
		
		public Edge(int start, int end, int weight) {
			super();
			this.start = start;
			this.end = end;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return this.weight - o.weight;
		}
	}
	
	private static void setEdge() {
		q = new PriorityQueue<>();
		
		for(int y = 0; y < N; y++) {
			int prev = 0;
			int curr = 0;
			for(int x = 0; x < M; x++) {
				curr = x;
				
				if(matrix[y][curr] == 0) continue;
				if(prev == 0) {
					prev = x;
					continue;
				}
				if(prev == curr) {
					continue;
				}

				if(curr - prev > 2) {
					q.offer(new Edge(matrix[y][prev], matrix[y][curr], curr - prev - 1));
				}
				
				prev = curr;
			}
		}
		
		for(int x = 0; x < M; x++) {
			int prev = 0;
			int curr = 0;
			for(int y = 0; y < N; y++) {
				curr = y;
				
				if(matrix[curr][x] == 0) continue;
				if(prev == 0) {
					prev = y;
					continue;
				}
				if(prev == curr) {
					continue;
				}

				if(curr - prev > 2) {
					q.offer(new Edge(matrix[prev][x], matrix[curr][x], curr - prev - 1));
				}
				
				prev = curr;
			}
		}
	}
	
	private static int findMst() {
		int ans = 0;
		
		p = new int[cnt + 1];
		for(int i = 1; i < (cnt + 1); i++) p[i] = i;
		
		for(Edge e : q) {
			int px = findSet(e.start);
			int py = findSet(e.end);
			
			if(px == py) continue;
			
			unionSet(px, py);
			ans += e.weight;
		}
		
		System.out.println(Arrays.toString(p));
		int prev = p[1];
		for(int i = 2; i < cnt; i++) {
			if(prev != p[i]) return -1;
		}
		return ans;
	}

	private static void unionSet(int px, int py) {
		p[py] = px;
	}

	private static int findSet(int x) {
		if(p[x] == x) return x;
		return p[x] = findSet(p[x]);
	}
}
