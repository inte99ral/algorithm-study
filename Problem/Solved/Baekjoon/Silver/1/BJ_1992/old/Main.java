import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.IOException;


public class Main {
  public static void main(String args[]) throws IOException, NumberFormatException {
    Main mainInstance = new Main();
    System.setIn(new FileInputStream("question/input.txt"));

    int N;
    boolean matrix[][];

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      N = Integer.parseInt(br.readLine());
      matrix = new boolean[N][N];

      for(int y = 0; y < N; y++) {
        String rawInput = br.readLine();
        for(int x = 0; x < N; x++) matrix[y][x] = rawInput.charAt(x) == '1';
      }

      br.close();
    }

    
    System.out.println(mainInstance.quadTree(matrix, 0, 0, N));
    return;
  }

  public String quadTree(boolean[][] matrix, int Y, int X, int L) {
    if(L == 1) return matrix[Y][X]? "1" : "0";
    String UL = quadTree(matrix, Y, X, L >> 1);
    String UR = quadTree(matrix, Y, X + (L >> 1), L >> 1);
    String DL = quadTree(matrix, Y + (L >> 1), X, L >> 1);
    String DR = quadTree(matrix, Y + (L >> 1), X + (L >> 1), L >> 1);

    // Compress
    if((UL.length() == 1) && (UL == UR) && (UL == DL) && (UL == DR)) return UL;

    return new StringBuilder().append('(').append(UL).append(UR).append(DL).append(DR).append(')').toString();
  }
}
