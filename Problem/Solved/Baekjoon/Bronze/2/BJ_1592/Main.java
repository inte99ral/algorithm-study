import java.io.FileInputStream;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt")); // -- 로컬 input.txt 입력 코드
    BufferedReader br;
    StringTokenizer st;
    int N; 
    int M;
    int L;
    int[] arr;
    int curr;
    int count;
    
    {
      br = new BufferedReader(new InputStreamReader(System.in));
      st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      L = Integer.parseInt(st.nextToken());
      arr = new int[N];
      arr[0] = 1;
      curr = 0;
      count = 0;
      br.close();
    }

    while(arr[curr] < M) {
      if(arr[curr] % 2 == 0) curr = (curr + N - L) % N;
      else curr = (curr + N + L) % N;
      arr[curr]++;
      count++;
    }

    System.out.println(count);

    return;
  }
}
