import java.util.ArrayList;
import java.util.PriorityQueue;
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

  private static class Edge implements Comparable<Edge>{
		int v1;
		int v2;
		int w;
		
		public Edge(int v1, int v2, int w) {
			this.v1 = v1;
			this.v2 = v2;
			this.w = w;
		}

		@Override
		public int compareTo(Edge o) {
			return this.w - o.w;
		}
	}	

  // # Implements Definition ====================
  public static void main(String[] args) {
    int V;
    int E;

    int size = 0;
		
    boolean[] selected;
    ArrayList<ArrayList<Edge>> edges;
    PriorityQueue<Edge> task;

    // * INPUT
    {
      Scanner sc = new Scanner(input);
      V = sc.nextInt(); // 정점의 갯수 0부터 시작
      E = sc.nextInt(); // 간선 갯수

      selected = new boolean[V];
      edges = new ArrayList<>();

      for (int v = 0; v < V; v++) {
        edges.add(new ArrayList<>());
      }

      for (int e = 0; e < E; e++) {
        int v1 = sc.nextInt();
        int v2 = sc.nextInt();
        int w = sc.nextInt();

        // System.out.printf("%d <--%d--> %d\n", v1, w, v2);

        // 양방향에서 접근
				edges.get(v1).add(new Edge(v1, v2, w));
        edges.get(v2).add(new Edge(v2, v1, w));
      }

      sc.close();
    }

    selected = new boolean[V];
    task = new PriorityQueue<>();

    // 1. 시작하면서 임의의 정점(여기선 0번) 정점 집합에 추가합니다.
    selected[0] = true;
    task.addAll(edges.get(0));

    System.out.println("[MST EDGE] :");

    // 2. 3번 과정을 가능하다면 V-1 개의 간선을 찾을 때까지 반복합니다.
    int count = 1;
    while (count < V) {
      // 3. 앞에서 만들어진 정점 집합에 인접한 정점들 중에서 가장 낮은 가중치의 간선으로 연결된 정점을 선택하여 정점 집합에 추가합니다.
      // 우선순위 큐(Priority Queue)에선 자동으로 가중치순으로 정렬됩니다.
      Edge target = task.poll();

      if (selected[target.v2]) continue;
      
      System.out.printf("%d <--%d--> %d\n", target.v1, target.w, target.v2);

      size += target.w;
      selected[target.v2] = true;
      task.addAll(edges.get(target.v2));
      count++;
    }

    // * OUTPUT
    {
      System.out.printf("\n[MST SIZE] : %d",size);
    }

    return;
  }
}