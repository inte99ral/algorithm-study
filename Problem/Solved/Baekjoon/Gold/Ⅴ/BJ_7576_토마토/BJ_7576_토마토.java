package BJ.Gold.G5;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/7576

public class BJ_7576_토마토 {
	public static BufferedReader br;
	public static StringTokenizer st;
	public static int M;
	public static int N;
	public static int[][] matrix;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		matrix = new int[N][M];
		Queue<Node> nodeQueue = new LinkedList<>();
		
		int tomato = 0;
		
		for(int y = 0; y < N; y++) {
			st = new StringTokenizer(br.readLine());
			for(int x = 0; x < M; x++) {
				int curr = Integer.parseInt(st.nextToken());
				if(curr == 1) nodeQueue.offer(new Node(y, x, 0));
				if(curr == 0) tomato++;
				matrix[y][x] = curr;
			}
		}
		
		int x = 0;
		int y = 0;
		int depth = 0;
		
		while(nodeQueue.size() != 0) {
			Node curr = nodeQueue.poll();
			x = curr.getX();
			y = curr.getY();
			depth = curr.getDepth();
			
			// U
			if((y > 0)&&(matrix[y - 1][x] == 0)) {
				matrix[y - 1][x] = 1;
				tomato--;
				nodeQueue.offer(new Node(y - 1, x, depth + 1));
			}
			
			// D
			if((y < N - 1)&&(matrix[y + 1][x] == 0)) {
				matrix[y + 1][x] = 1;
				tomato--;
				nodeQueue.offer(new Node(y + 1, x, depth + 1));
			}
			
			// L
			if((x > 0)&&(matrix[y][x - 1] == 0)) {
				matrix[y][x - 1] = 1;
				tomato--;
				nodeQueue.offer(new Node(y, x - 1, depth + 1));
			}
			// R
			if((x < M - 1)&&(matrix[y][x + 1] == 0)) {
				matrix[y][x + 1] = 1;
				tomato--;
				nodeQueue.offer(new Node(y, x + 1, depth + 1));
			}
		}
		
		if(tomato > 0) System.out.println(-1);
		else System.out.println(depth);
	}
	
	public static class Node {
		private int y;
		private int x;
		private int depth;

		public Node(int y, int x, int depth) {
			super();
			this.y = y;
			this.x = x;
			this.depth = depth;
		}
		
		public int getY() {return y;}
		public void setY(int y) {this.y = y;}

		public int getX() {return x;}
		public void setX(int x) {this.x = x;}

		public int getDepth() {return depth;}
		public void setDepth(int depth) {this.depth = depth;}
		
		@Override
		public String toString() {
			return "[" + y + "," + x + "]";
		}
	}
}
