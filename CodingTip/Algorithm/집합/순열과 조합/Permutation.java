import java.util.Arrays;

class Permutation {

  // -- Methods ====================

  public static void perm(int[] arr, int selectNumber) {
    permRecur(arr, selectNumber, 0, new int[selectNumber], 0);
    return;
  }

  public static void permRecur(
    int[] origin,
    int selectNumber,
    int selectData,
    int[] fixed,
    int index
  ) {
    // 전부 선택했으니 출력
    if (index == selectNumber) {
      System.out.println(Arrays.toString(fixed));
      return;
    }

    for (int i = 0; i < origin.length; i++) {
      // 해당 숫자는 이미 선택했었음
      if ((selectData & 1 << i) > 0) continue;

      // 선택함
      fixed[index] = origin[i];
      permRecur(origin, selectNumber, selectData | 1 << i, fixed, index + 1);
    }
    return;
  }

  // -- Run ====================
  public static void main(String[] args) {
    int[] arr = { 1, 2, 3 };
    perm(arr, 2);
    return;
  }
}
