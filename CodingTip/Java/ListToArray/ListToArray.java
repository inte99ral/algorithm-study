package CodingTip.Java.ListToArray;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListToArray {

  public static void main(String[] args) throws Exception {
    List<Integer> tempList = new ArrayList<>();
    for (int i : new int[] { 1, 2, 3, 4 }) tempList.add(i);
    System.out.println(Arrays.toString(tempList.stream().mapToInt(Integer::intValue).toArray()));
    return;
  }
}
