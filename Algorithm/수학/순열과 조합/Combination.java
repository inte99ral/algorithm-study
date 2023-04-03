import java.util.Arrays;

class Combination {

  // -- Methods ====================

  public static void comb(int[] arr, int selectNumber) {
    combRecur(arr, selectNumber, -1, new int[selectNumber], 0);
    return;
  }

  public static void combRecur(
    int[] origin,
    int selectNumber,
    int selectIndex,
    int[] fixed,
    int index
  ) {
    // 전부 선택했으니 출력
    if (index == selectNumber) {
      System.out.println(Arrays.toString(fixed));
      return;
    }

    for (int i = selectIndex + 1; i < origin.length; i++) {
      fixed[index] = origin[i];
      combRecur(origin, selectNumber, i, fixed, index + 1);
    }
    return;
  }

  // -- Run ====================
  public static void main(String[] args) {
    int[] arr = { 1, 2, 3 };
    comb(arr, 3);
    return;
  }
}
