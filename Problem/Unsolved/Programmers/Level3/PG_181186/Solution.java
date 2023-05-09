import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

class Solution {

  // -- Run
  public static void main(String[] args) throws IOException {
    Solution solutionClass = new Solution();

    System.setIn(new FileInputStream("input.txt"));
    Scanner sc = new Scanner(System.in);

    System.out.println(solutionClass.solution(sc.nextInt()));

    sc.close();
    return;
  }

  // -- Methods
  private int answer;
  private int height;
  private int width;
  private boolean[][] matrix;
  private Stack<Integer> debugStack;

  public int solution(int n) {
    answer = 0;
    height = 3;
    width = n;
    matrix = new boolean[height][width];
    // debugStack = new Stack<Integer>();

    recur(0, 0);

    return answer;
  }

  public void recur(int y, int x) {
    if (x >= width) {
      recur(y + 1, 0);
      return;
    }

    if (y >= height) {
      if (answer >= 1000000007) answer = 0;
      answer++;
      // System.out.println(debugStack.toString());
      return;
    }

    if (matrix[y][x]) {
      recur(y, x + 1);
      return;
    }

    // -
    if (x + 2 < width && !matrix[y][x + 1] && !matrix[y][x + 2]) {
      matrix[y][x] = true;
      matrix[y][x + 1] = true;
      matrix[y][x + 2] = true;

      // debugStack.push(1);

      recur(y, x + 3);

      matrix[y][x] = false;
      matrix[y][x + 1] = false;
      matrix[y][x + 2] = false;
      // debugStack.pop();
    }

    // |
    if (y + 2 < height && !matrix[y + 1][x] && !matrix[y + 2][x]) {
      matrix[y][x] = true;
      matrix[y + 1][x] = true;
      matrix[y + 2][x] = true;

      // debugStack.push(2);

      recur(y, x + 1);

      matrix[y][x] = false;
      matrix[y + 1][x] = false;
      matrix[y + 2][x] = false;
      // debugStack.pop();
    }

    // ⌋
    if (y + 1 < height && x - 1 >= 0 && !matrix[y + 1][x] && !matrix[y + 1][x - 1]) {
      matrix[y][x] = true;
      matrix[y + 1][x] = true;
      matrix[y + 1][x - 1] = true;

      // debugStack.push(3);

      recur(y, x + 1);

      matrix[y][x] = false;
      matrix[y + 1][x] = false;
      matrix[y + 1][x - 1] = false;
      // debugStack.pop();
    }

    // ⌊
    if (y + 1 < height && x + 1 < width && !matrix[y + 1][x] && !matrix[y + 1][x + 1]) {
      matrix[y][x] = true;
      matrix[y + 1][x] = true;
      matrix[y + 1][x + 1] = true;

      // debugStack.push(4);

      recur(y, x + 1);

      matrix[y][x] = false;
      matrix[y + 1][x] = false;
      matrix[y + 1][x + 1] = false;
      // debugStack.pop();
    }

    // ⌈
    if (y + 1 < height && x + 1 < width && !matrix[y][x + 1] && !matrix[y + 1][x]) {
      matrix[y][x] = true;
      matrix[y][x + 1] = true;
      matrix[y + 1][x] = true;

      // debugStack.push(5);

      recur(y, x + 2);

      matrix[y][x] = false;
      matrix[y][x + 1] = false;
      matrix[y + 1][x] = false;
      // debugStack.pop();
    }

    // ⌉
    if (y + 1 < height && x + 1 < width && !matrix[y][x + 1] && !matrix[y + 1][x + 1]) {
      matrix[y][x] = true;
      matrix[y][x + 1] = true;
      matrix[y + 1][x + 1] = true;

      // debugStack.push(6);

      recur(y, x + 2);

      matrix[y][x] = false;
      matrix[y][x + 1] = false;
      matrix[y + 1][x + 1] = false;
      // debugStack.pop();
    }

    return;
  }
}
