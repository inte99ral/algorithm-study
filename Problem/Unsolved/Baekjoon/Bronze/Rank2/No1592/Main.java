package Problem.Unsolved.Baekjoon.Bronze.Rank2.No1592;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

  private static BufferedReader br;
  private static StringTokenizer st;
  private static int N;
  private static int M;
  private static int L;

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));
    st = new StringTokenizer("1 5 5");

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    L = Integer.parseInt(st.nextToken());

    solution(N, M, L);

    br.close();
    return;
  }

  public static int solution(int N, int M, int L) {
    List<Integer> players = new LinkedList<Integer>();
    int index = 0;
    int count = 0;

    for (int i = 0; i < N; i++) players.add(0);

    while (players.get(index) < M - 1) {
      players.set(index, players.get(index) + 1);
      if (players.get(index) % 2 == 1) {
        // index = (index + L)
      } else {}
      count++;
    }

    return count;
  }
}
