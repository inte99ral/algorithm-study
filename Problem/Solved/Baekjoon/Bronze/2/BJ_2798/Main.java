/**
 * java Main.java
 */
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException, NumberFormatException{
    System.setIn(new FileInputStream("question/input.txt"));
    int answer = 0;
    int N;
    int M;
    int[] card;

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String[] rawInput = br.readLine().split(" ");
      N = Integer.parseInt(rawInput[0]);
      M = Integer.parseInt(rawInput[1]);
      card = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
      br.close();
    }

    for(int i = 0; i < N - 2; i++) {
      if(card[i] > M) continue;
      for(int j = i + 1; j < N - 1; j++) {
        if(card[i] + card[j] > M) continue;
        for(int k = j + 1; k < N; k++) {
          if(card[i] + card[j] + card[k] > M) continue;
          if(card[i] + card[j] + card[k] < answer) continue;
          answer = card[i] + card[j] + card[k];
        }
      }
    }

    System.out.println(answer);
    return;
  }
}