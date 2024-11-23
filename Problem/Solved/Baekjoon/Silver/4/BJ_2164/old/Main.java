import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("question/input.txt")); // -- local input.txt

    int N;
    Queue<Integer> deck = new LinkedList<>();

    {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      N = Integer.parseInt(br.readLine());
      br.close();
    }

    for(int i = 1; i <= N; i++) deck.offer(i);
    while(deck.size() != 1){
      deck.poll();
      deck.offer(deck.poll());
    }

    System.out.println(deck.poll());
  }
}
