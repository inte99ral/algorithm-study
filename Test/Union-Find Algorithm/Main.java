import java.util.Scanner;

public class Main {
	// # Global Variable & Constant================
	private static String input = 
		"9 8\n" +
		"1 2\n" +
		"1 4\n" +
		"2 4\n" +
		"3 5\n" +
		"5 7\n" +
		"6 8\n" +
		"6 9\n" +
		"8 9\n";

	private static int[] nodes;
	
	// # Implements Definition ====================
	public static void main(String[] args) throws Exception {
		Main mainInstance = new Main();
		int V;
		int E;

		// * INPUT
		{
			Scanner sc = new Scanner(input);

			V = sc.nextInt();
			E = sc.nextInt();

			nodes = new int[V + 1];

			for (int v = 1; v <= V; v++) {
				mainInstance.makeSet(v);
			}

			for (int e = 0; e < E; e++) {
				mainInstance.unionSet(sc.nextInt(), sc.nextInt());
			}

			sc.close();
		}

		// * OUTPUT_1
		{
			StringBuffer sb = new StringBuffer();
			sb.append("[NODE NUM] : ");
			for (int v = 1; v <= V; v++) {
				cout << v << ", ";
			}
			cout << "\b\b \n";
	
			cout << "[ROOT NUM] : ";
			for (int v = 1; v <= V; v++) {
				cout << nodes[v] << ", ";
			}
			cout << "\b\b \n\n";
			System.out.print(sb);
		}

		for (int v = 1; v <= V; v++) {
			System.out.print(nodes[v] + ", ");
		}
	}

	void makeSet(int x) {
		nodes[x] = x;
	}

	int findSet(int x) {
		if(x == nodes[x]) return x;
		return nodes[x] = findSet(nodes[x]); // Path Compression
	}
	
	void unionSet(int x, int y) {
		// System.out.println(x + ", " + y);
		// System.out.println(findSet(x) + ", " + findSet(y) + "\n");
		nodes[findSet(y)] = findSet(x);
	}
}
