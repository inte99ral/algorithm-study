/**
 * solution 메소드만 코딩하면 되기 때문에 main 만 지울 것
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Main {

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("input.txt"));

    Main mainClass = new Main();
    List<Integer> tempList = new ArrayList<>();
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    for (String line = br.readLine(); line != null; line = br.readLine()) {
      for (String str : line.substring(1, line.length() - 1).split(",")) {
        tempList.add(Integer.parseInt(str));
      }
    }

    br.close();

    mainClass.solution(tempList.stream().mapToInt(Integer::intValue).toArray());

    return;
  }

  public int solution(int[] data) {
    System.out.println(Arrays.toString(data));
    return 0;
  }
}
