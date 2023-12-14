import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
  private static BufferedReader br;
  private static StringTokenizer st;
  private static StringBuilder sb;

  public static void main(String[] args) throws IOException, NumberFormatException {
    int[] arr;
    int L;
    int N;
    int target;

    System.setIn(new FileInputStream("question/input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    L = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    arr = new int[L + 1];
    for(int l = 1; l <= L; l++) {
      arr[l] = Integer.parseInt(st.nextToken());
    }

    N = Integer.parseInt(br.readLine());

    for(int n = 0; n < N; n++) {
      st = new StringTokenizer(br.readLine());
      switch(st.nextToken()) {
        case "1": // boy
          target = Integer.parseInt(st.nextToken());
          for(int i = 1; target * i <= L; i++) {
            arr[target * i] = 1 - arr[target * i];
          }
          break;

        case "2": // girl
          target = Integer.parseInt(st.nextToken());
          for(int i = 0; target - i > 0 && target + i <= L; i++) {
            if(arr[target - i] != arr[target + i]) break;
            int temp = 1 - arr[target - i];
            arr[target - i] = temp;
            arr[target + i] = temp;
          }
          break;
      }
    }

    sb = new StringBuilder();
    for(int i = 1; i <= L; i++) {
      sb.append(arr[i]).append(' ');
      if(i % 20 == 0) sb.append('\n');
    }

    System.out.println(sb.toString());
    

    br.close();
    return;
  }
}
