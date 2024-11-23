import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    int N;
    int count = 0;
    String seat;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());
      seat = br.readLine();
      br.close();
    }

    for(int i = 0; i < N; i++) if(seat.charAt(i) == 'L') count++;

    System.out.println(N - (count > 0? count / 2 - 1 : 0));
  }
}
