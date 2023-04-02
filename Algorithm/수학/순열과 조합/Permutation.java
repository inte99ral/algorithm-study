class Permutation {

  // -- Methods ====================
  public static void perm(int[] arr, int selectNumber) {
    return;
  }

  /**
   *
   * @param origin 원본
   * @param selectNumber
   * @param fixed
   * @param data
   * @param length
   */
  public static void permRecur(
    int[] origin,
    int selectNumber,
    int selectData,
    int[] fixed,
    int index,
    int length
  ) {
    if (length == selectNumber) {
      System.out.print("[ ");
      for (int i : fixed) {
        System.out.print(i);
        System.out.print(" ");
      }
      System.out.println("]");
      return;
    }

    for (int i : origin) {
      permRecur(origin, selectNumber, fixed, data, length);
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
