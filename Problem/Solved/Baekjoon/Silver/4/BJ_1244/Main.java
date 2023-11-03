import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  private static BufferedReader br;
  private static StringTokenizer st;

  public static void main(String[] args) throws IOException, NumberFormatException {
    int[] arr;
    int L;
    int N;

    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    L = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    // arr = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
    arr = new int[L + 1];
    for(int l = 1; l <= L; l++) {
      arr[l] = Integer.parseInt(st.nextToken());
    }

    N = Integer.parseInt(br.readLine());

    for(int n = 0; n < N; n++) {
      st = new StringTokenizer(br.readLine());
      switch(st.nextToken()) {
        case "1": // boy
          int target = Integer.parseInt(st.nextToken());
          for(int i = 1; target * i <= L; i++) {
            arr[target * i] = 1 - arr[target * i];
          }
          break;
        case "2": // girl
          int target = Integer.parseInt(st.nextToken());
          for()
          break;
      }
    }
    

    br.close();
    return;
  }
}
