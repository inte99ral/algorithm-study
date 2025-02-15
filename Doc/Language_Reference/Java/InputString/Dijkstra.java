package 그래프.패스파인딩;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

// 다익스트라
public class Dijkstra {
	static class Node {
		int v;
		int weight;
		
		public Node(int v, int weight) {
			this.v = v;
			this.weight = weight;
		}
	}
	
	static String input = 
			"6 11\r\n" + 
			"0 1 4\r\n" + 
			"0 2 2\r\n" + 
			"0 5 25\r\n" + 
			"1 3 8\r\n" + 
			"1 4 7\r\n" + 
			"2 1 1\r\n" + 
			"2 4 4\r\n" + 
			"3 0 3\r\n" + 
			"3 5 6\r\n" + 
			"4 3 5\r\n" + 
			"4 5 12";
	
	static final int INF = Integer.MAX_VALUE;
	static int V, E;
	static List<Node>[] adjList; // 인접리스트
	static int[] dist;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(input);
		
		V = sc.nextInt();
		E = sc.nextInt();
		
		adjList = new ArrayList[V];
		
		for(int i = 0; i < V; i++) adjList[i] = new ArrayList<>();
		
		dist = new int[V];
		Arrays.fill(dist, INF);
		
		for(int i = 0; i < E; i++) {
			int st = sc.nextInt();
			int ed = sc.nextInt();
			int w = sc.nextInt();
//			adjList[]
		}
		
		
		dijkstra(0);
		
		System.out.println();
	}
	
	
	static void dijkstra(int st) {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited =  new boolean[V];
		
		pq.add(new Node(st, 0));
		dist[st] = 0;
		
		while(!pq.isEmpty()) {
			Node curr = pq.poll();
			
			if(visited[curr.v]) continue;
//			vistied[curr.v] = true; // 선택했당
			
			for(Node node : adjList[curr.v]) {
				if(dist[node.v] > dist[curr.v] + node.weight) {
					
				}
			}
		}
		
	}
}
