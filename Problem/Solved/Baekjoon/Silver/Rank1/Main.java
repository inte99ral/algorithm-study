import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();
    for (int t = 0; t < 4; t++) {
      String[] line = br.readLine().split(" ");
      int x1 = Integer.parseInt(line[0]);
      int y1 = Integer.parseInt(line[1]);
      int p1 = Integer.parseInt(line[2]);
      int q1 = Integer.parseInt(line[3]);

      int x2 = Integer.parseInt(line[4]);
      int y2 = Integer.parseInt(line[5]);
      int p2 = Integer.parseInt(line[6]);
      int q2 = Integer.parseInt(line[7]);

      if (p1 < x2 || q1 < y2 || p2 < x1 || q2 < y1) {
        sb.append("d").append("\n");
      } else if (
        (x1 == p2 && y1 == q2) ||
        (p1 == x2 && y1 == q2) ||
        (p1 == x2 && q1 == y2) ||
        (x1 == p2 && q1 == y2)
      ) {
        sb.append("c").append("\n");
      } else if (x1 == p2 || p1 == x2 || q1 == y2 || q2 == y1) {
        sb.append("b").append("\n");
      } else {
        sb.append("a").append("\n");
      }
    }
    br.close();
    System.out.print(sb);
    return;
  }
}
