/**
 * java Main.java
 */
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    BufferedReader br;
    StringTokenizer st;

    int N;
    int answer = 0;
    boolean[][] matrix = new boolean[101][101];

    {
      br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());

      for(int n = 0; n < N; n++) {
        int xCoord;
        int yCoord;

        st = new StringTokenizer(br.readLine());
        xCoord = Integer.parseInt(st.nextToken());
        yCoord = Integer.parseInt(st.nextToken());

        for(int y = yCoord; y < yCoord + 10; y++) {
          for(int x = xCoord; x < xCoord + 10; x++) {
            if(!matrix[y][x]) {
              matrix[y][x] = true;
              answer++;
            }
          }
        }
      }

      br.close();
    }

    System.out.println(answer);
  }
}