import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Solution {
  // -- Local Input ====================
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("question/input.txt"));
    Solution solInstance = new Solution();

    LinkedList<LinkedList<Integer>> rawInput = new LinkedList<LinkedList<Integer>>();
    int[][] input;

    {
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
    }

    input = rawInput.stream().map(e -> e.stream().mapToInt(i -> i).toArray()).toArray(int[][]::new);

    System.out.println(solInstance.solution(input));
    return;
  }

  // -- Solution =======================
  /**
   * 이상하게 풀었음 ㄹㅇ
   */
  public int solution(int[][] targets) {
    ArrayList<ArrayList<Integer>> memory = new ArrayList<ArrayList<Integer>>();

    // 소팅부터 박는다
    Arrays.sort(targets, (x, y) -> (x[0] - y[0]));

    ArrayList<Integer> tempIntList = new ArrayList<Integer>();
    tempIntList.add(targets[0][0]);
    tempIntList.add(targets[0][1]);
    tempIntList.add(targets[0][0]);

    memory.add(tempIntList);

    for (int i = 1; i < targets.length; i++) {
      if (targets[i][0] < memory.get(memory.size() - 1).get(1)) {
        memory
          .get(memory.size() - 1)
          .set(0, targets[i][0]);
        if (targets[i][1] < memory.get(memory.size() - 1).get(1))
        memory
          .get(memory.size() - 1)
          .set(1, targets[i][1]);
        memory.get(memory.size() - 1).add(targets[i][0]);
      } else {
        ArrayList<Integer> tempMemory = new ArrayList<Integer>();
        tempMemory.add(targets[i][0]);
        tempMemory.add(targets[i][1]);
        tempMemory.add(targets[i][0]);

        memory.add(tempMemory);
      }
    }

    return memory.size();
  }
}
