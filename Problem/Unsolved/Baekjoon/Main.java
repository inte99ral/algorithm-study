import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br;
    int answer = 0;

    br = new BufferedReader(new InputStreamReader(System.in));
    {
      for (int i = 0; i < 10; i++) {
        int tempInt = Integer.parseInt(br.readLine());
        if(answer + tempInt <= 100) {

        } else {
          if(100 - answer < answer + tempInt - 100) {
            break;
          }
          else if() {

          }
        }
      }
    }
    br.close();
  }
}
