import java.util.ArrayList;
import java.util.Arrays;

class Solution {

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
        memory.get(memory.size() - 1).set(0, targets[i][0]);
        if (targets[i][1] < memory.get(memory.size() - 1).get(1)) memory
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

    // 디버깅 코드
    // System.out.println("[디버깅]");
    // {
    //     for(ArrayList iList : memory)
    //         System.out.println(iList.toString());
    // }

    return memory.size();
  }
}
