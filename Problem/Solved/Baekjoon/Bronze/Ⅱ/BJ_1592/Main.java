import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  private static BufferedReader br;
  private static StringTokenizer st;
  private static int N;
  private static int M;
  private static int L;

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));
    st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    L = Integer.parseInt(st.nextToken());

    System.out.println(solution(N, M, L));

    br.close();
    return;
  }

  public static int solution(int N, int M, int L) {
    int[] players = new int[N];
    int index = 0;
    int count = 0;

    players[index] = 1;

    while (players[index] < M) {
      index = (N + ((index - L + (2 * L * (players[index] % 2))) % N)) % N;
      count++;
      players[index]++;
    }

    return count;
  }
}
