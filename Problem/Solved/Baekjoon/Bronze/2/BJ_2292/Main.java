import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt")); // -- 로컬
    BufferedReader br;
    int N;
    int answer;

    {
      br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());
      br.close();
    }

    answer = 1;
    while ((answer * (answer - 1) * 3 + 1) < N) answer++;
    System.out.println(answer);
    return;
  }
}
