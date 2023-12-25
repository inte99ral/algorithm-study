import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  static BufferedReader br;
  static int N;
  static int count;
  static String seat;
  static boolean[] holder;

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));
    {
      N = Integer.parseInt(br.readLine());
      count = 0;
      seat = br.readLine();
      holder = new boolean[N + 1];
    }
    br.close();

    for(int i = 0; i < N; i++) {
      if(seat.charAt(i) == 'L') {
        count++;
      }
    }

    count = count > 0? count / 2 - 1 : 0;
    System.out.println(N - count);
  }
}
