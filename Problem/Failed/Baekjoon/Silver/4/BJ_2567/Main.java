import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());
    int answer = 0;
    boolean[][] matrix = new boolean[100][100];

    for (int t = 0; t < T; t++) {
      String[] lineArr = br.readLine().split(" ");
      int X = Integer.parseInt(lineArr[0]);
      int Y = Integer.parseInt(lineArr[1]);

      for (int x = X; x < X + 10; x++) {
        for (int y = Y; y < Y + 10; y++) {
          matrix[x][y] = true;
        }
      }
    }
    br.close();

    for (int x = 0; x < 100; x++) {
      for (int y = 0; y < 100; y++) {
        if (matrix[x][y]) {
          if (x == 0 || !matrix[x - 1][y]) answer++;
          if (x == 99 || !matrix[x + 1][y]) answer++;
          if (y == 0 || !matrix[x][y - 1]) answer++;
          if (y == 99 || !matrix[x][y + 1]) answer++;
        }
      }
    }

    System.out.println(answer);
    return;
  }
}
