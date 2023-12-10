import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

class Solution {

  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("input.txt"));

    Solution solutionClass = new Solution();
    List<Integer> tempList = new ArrayList<>();
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    br.close();

    for (String str : line.substring(1, line.length() - 1).split(",")) {
      tempList.add(Integer.parseInt(str));
    }

    System.out.println(solutionClass.solution(tempList.stream().mapToInt(i -> i).toArray()));
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
