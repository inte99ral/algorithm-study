import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  private static final int MATRIX_SIZE = 101;
  private static final int PAPER_SIZE = 10;

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    
    BufferedReader br;
    boolean[][] matrix = new boolean[MATRIX_SIZE][MATRIX_SIZE];
    int answer = 0;

    {
      br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine());

      for(;N-- > 0;) {
        String[] XY = br.readLine().split(" ");
        int X = Integer.parseInt(XY[0]);
        int Y = Integer.parseInt(XY[1]);
        for(int y = Y; y < Y + PAPER_SIZE; y++) for(int x = X; x < X + PAPER_SIZE; x++) matrix[y][x] = true;
      }

      br.close();
    }

    for(int y = 0; y < MATRIX_SIZE; y++) {
      for(int x = 0; x < MATRIX_SIZE; x++) {
        if(matrix[x][y]) {
          if (!matrix[x - 1][y]) answer++;
          if (!matrix[x + 1][y]) answer++;
          if (!matrix[x][y - 1]) answer++;
          if (!matrix[x][y + 1]) answer++;
        }
      }
    }

    System.out.println(answer);
    return;
  }
}
