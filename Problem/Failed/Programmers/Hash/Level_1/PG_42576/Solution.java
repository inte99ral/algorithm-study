import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Solution {
  // -- Local Input ====================
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    Solution solInstance = new Solution();

    int[][] input;
    
    {
      LinkedList<LinkedList<Integer>> rawInput = new LinkedList<LinkedList<Integer>>();
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine(), "[, ]");

      while(st.hasMoreTokens()) {
        rawInput.add(
          new LinkedList<Integer>(Arrays.asList(
            Integer.parseInt(st.nextToken()), 
            Integer.parseInt(st.nextToken())
          ))
        );
      }
      br.close();
      input = rawInput.stream().map(e -> e.stream().mapToInt(i -> i).toArray()).toArray(int[][]::new);
    }

    System.out.println("[answer]: " + solInstance.solution(input));
    return;
  }

  // -- Solution =======================
  /**
   * java Solution.java
   * 2차원 배열 데이터 전용
   */
  public int solution(int[][] datas) {
    int answer = 0;

    for(int[] data : datas) System.out.println(new StringBuffer()
      .append('[')
      .append(data[0])
      .append(", ")
      .append(data[1])
      .append(']')
    );

    return answer;
  }
}
