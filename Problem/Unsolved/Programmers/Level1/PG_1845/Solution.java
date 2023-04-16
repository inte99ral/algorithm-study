import java.util.HashMap;

class Solution {

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
