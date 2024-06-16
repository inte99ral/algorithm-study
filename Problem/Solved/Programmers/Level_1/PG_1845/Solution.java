/**
 * java Solution.java
 */
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

class Solution {

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("question/input.txt"));
    Solution solInstance = new Solution();

    int[] input;
    {
      ArrayList<Integer> rawInput = new ArrayList<>();
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine(),"[, ]");

      while (st.hasMoreTokens()) rawInput.add(Integer.parseInt(st.nextToken()));
      input = rawInput.stream().mapToInt(e -> e).toArray();
      br.close();
    }

    System.out.println(solInstance.solution(input));
    return;
  }

  public int solution(int[] nums) {
    HashMap<Integer, Integer> monsterMap = new HashMap<Integer, Integer>();

    for (int monster : nums) {
      if (!monsterMap.containsKey(monster)) {
        monsterMap.put(monster, 1);
      }
    }

    if (monsterMap.size() < nums.length / 2) return monsterMap.size();
    return nums.length / 2;
  }
}
