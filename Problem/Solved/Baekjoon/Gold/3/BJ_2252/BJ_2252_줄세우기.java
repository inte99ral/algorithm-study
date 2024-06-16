package BJ.Gold.G3;
// https://www.acmicpc.net/problem/2252

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;



public class BJ_2252_줄세우기 {
	private static BufferedReader br;
	private static StringTokenizer st;
	
	private static int N;
	private static int M;
	
	private static ArrayList<Integer> sData;
	private static Map<Integer, ArrayList<Integer>> sMap;
	
	public static void main(String[] args) throws Exception {
		init();
		
//		System.out.println(sData);
		
		topologicalSort();
		return;
	}

	private static void init() throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		sData = new ArrayList<>();
		sMap = new HashMap<Integer, ArrayList<Integer>>();
		
		for(int i = 0; i <= N; i++) sData.add(0);
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			
			if(!sMap.containsKey(start)) sMap.put(start, new ArrayList<>());
			
			sMap.get(start).add(end);
			sData.set(end, sData.get(end) + 1);
		}
		
		return;
	}
	
	private static void topologicalSort() {
		Queue<Integer> sQueue = new LinkedList<>();
		
		for(int i = 1; i < N + 1; i++) {
			if(sData.get(i) != 0) continue;
			sQueue.offer(i);
		}
		
		while(!sQueue.isEmpty()) {
			int start = sQueue.poll();
			
			System.out.print(start);
			System.out.print(' ');
			
			if(!sMap.containsKey(start)) continue;
			
			for(int end : sMap.get(start)) {
				sData.set(end, sData.get(end) - 1);
				if(sData.get(end) == 0) sQueue.offer(end);
			}
			
			sMap.remove(start);
		}
	}
}
