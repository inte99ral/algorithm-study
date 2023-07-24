package BJ.Gold;

import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class BJ_15686_치킨배달 {
	private static int N;
	private static int M;
	private static int minDistance;
	
	private static ArrayList<int[]> chicken = new ArrayList<>();
	private static ArrayList<int[]> house = new ArrayList<>();
	private static int[][] distance;
	private static Scanner sc;
	
	public static void main(String[] args) throws Exception {
		sc = new Scanner(new FileInputStream("input.txt"));
		
		N = sc.nextInt();
		M = sc.nextInt();
		
		int chickenCnt = 0;
		int houseCnt = 0;
		
		for(int y = 0; y < N; y++) {
			for(int x = 0; x < N; x++) {
				int curr = sc.nextInt();
				if(curr == 1) house.add(new int[] {y, x});
				if(curr == 2) chicken.add(new int[] {y, x});
			}
		}
		
		chickenCnt = chicken.size();
		houseCnt = house.size();
		
		distance = new int[house.size()][chicken.size()];
		for(int y = 0; y < house.size(); y++) {
			for(int x = 0; x < chicken.size(); x++) {
				distance[y][x] = Math.abs(house.get(y)[0] - chicken.get(x)[0]) + Math.abs(house.get(y)[1] - chicken.get(x)[1]);
			}
		}
		System.out.println(minChickenDistance(distance, chickenCnt, chickenCnt - M, 0, 0));
	}
	
	public static int minChickenDistance(int[][] distance, int n, int r, int cnt, int idx) {
		if(cnt == r) {
			return chickenDistance(distance);
		}
		
		int result = Integer.MAX_VALUE;
		
		for(int i = idx; i < n; i++) {
			int curr = minChickenDistance(removeChicken(distance, i), n, r, cnt + 1, i + 1);
			if(curr < result) result = curr;
		}
		
		return result;
	}
	
	public static int chickenDistance(int[][] distance) {
		int result = 0;
		for(int[] dArr : distance) {
			int min = Integer.MAX_VALUE;
			for(int d : dArr) {
				if(min > d) min = d;
			}
			result += min;
		}
		return result;
	}
	
	public static int[][] removeChicken(int[][] distance, int i) {
		int Y = distance.length;
		int X = distance[0].length;
		int[][] newDistance = new int[Y][X];
		
		for(int y = 0; y < Y; y++) {
			for(int x = 0; x < X; x++) {
				if(x == i) newDistance[y][x] = Integer.MAX_VALUE;
				else newDistance[y][x] = distance[y][x];
			}
		}
		
		return newDistance;
	}
}
