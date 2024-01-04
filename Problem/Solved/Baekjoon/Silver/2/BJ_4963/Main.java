import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) {
    System.setIn(new FileInputStream("question\\input.txt"));

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      String input = br.readLine();

      System.out.println(input.charAt(0));
      br.close();
    }

    return;
  }
}
