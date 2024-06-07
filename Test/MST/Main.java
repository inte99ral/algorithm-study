import java.util.Arrays;
import java.util.Scanner;

public class Main {
  // # Global Variable & Constant================
  private static String input =
    "10 21\n" +
    "0 1 9\n" +
    "0 2 9\n" +
    "0 9 8\n" +
    "0 8 18\n" +
    "1 2 3\n" +
    "1 4 6\n" +
    "2 3 2\n" +
    "2 4 4\n" +
    "2 9 9\n" +
    "3 4 2\n" +
    "3 5 9\n" +
    "3 9 8\n" +
    "4 5 9\n" +
    "5 6 4\n" +
    "5 7 5\n" +
    "5 9 7\n" +
    "6 7 1\n" +
    "6 8 4\n" +
    "7 8 3\n" +
    "7 9 9\n" +
    "8 9 10\n" +
    "8 10 18\n" +
    "9 10 8\n";

		private static int[][] graph;

  // # Implements Definition ====================
  public static void main(String[] args) {
    Main mainInstance = new Main(); 
    int V;
    int E;

    int size = 0;

		// 1. 시작하면서 시작 정점을 비어있는 정점 집합에 추가합니다.
		// 2. 앞에서 만들어진 정점 집합에 인접한 정점들 중에서 가장 낮은 가중치의 간선으로 연결된 정점을 선택하여 정점 집합에 추가합니다.
		// 3. 2번 과정을 가능하다면 V-1 번 반복합니다.

    // * INPUT
    {
      Scanner sc = new Scanner(input);
      V = sc.nextInt(); // 정점의 갯수 0부터 시작
      E = sc.nextInt(); // 간선 갯수
			graph = new int[V][V]; // 양방향으로 접근가능한 V² 크기 데이터

      for(int i = 0; i < E; i++) {
        int v1 = sc.nextInt();
        int v2 = sc.nextInt();
        int w = sc.nextInt();

				graph[v1][v2] = graph[v2][v1] = w; 
      }

      sc.close();
    }

    boolean[] selected = new boolean[V];

    for(int i = 0; i < V; i++) {
      mainInstance.makeSet(i);
    }

    for(int i = 0; i < E; i++) {
      int rootX = mainInstance.findSet(edges[i][0]);
      int rootY = mainInstance.findSet(edges[i][1]);

      if(rootX != rootY) {
        mainInstance.unionSet(rootX, rootY);
        size += edges[i][2];
      }
    }

    // * OUTPUR
    {
      System.out.printf("[MST SIZE] : %d",size);
    }

    return;
  }

  void makeSet(int x) {
    nodes[x] = x;
  }

  int findSet(int x) {
    if(x == nodes[x]) return x;
    return nodes[x] = findSet(nodes[x]); // Path compression
  }

  void unionSet(int x, int y) {
    nodes[findSet(y)] = findSet(x);
  }
}