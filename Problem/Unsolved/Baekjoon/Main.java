import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    boolean[][] matrix = new boolean[100][100];
    int answer = 0;

    for (int n = 0; n < N; n++) {
      String[] strArr = br.readLine().split(" ");
      int X = Integer.parseInt(strArr[0]);
      int Y = Integer.parseInt(strArr[1]);

      for (int y = Y; y < Y + 10; y++) {
        for (int x = X; x < X + 10; x++) {
          if (!matrix[y][x]) {
            matrix[y][x] = true;
            answer++;
          }
        }
      }
    }

    br.close();
    System.out.println(answer);
    return;
  }
}
