import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  private int N;
  private int M;
  private int answer;

  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    Main mainInstance = new Main();
    int[] cards;

    {
      BufferedReader br;
      int[] tempArr;

      br = new BufferedReader(new InputStreamReader(System.in));
      tempArr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
      N = tempArr[0];
      M = tempArr[1];
      cards = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
      br.close();
    }

    System.out.println(Arrays.toString(cards));
    mainInstance.comb(cards, 3);
  }

  public void comb(int[] arr, int select) {
    combRecur(arr, new int[select], 0, select);
    return;
  }

  private void combRecur(int[] origin, int[] selected, int index, int count) {
    if (count == 0) {
      int sum = 0;
      for (int i : selected) {
        sum += i;
      }
      return;
    }

    if (index == origin.length) {
      return;
    }

    selected[selected.length - count] = origin[index];
    combRecur(origin, selected, index + 1, count - 1);
    combRecur(origin, selected, index + 1, count);
    return;
  }
}
