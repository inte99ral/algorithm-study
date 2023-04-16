import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

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
  private int[][] matrix;
  private int answer;
  private int height;
  private int width;

  public int solution(int n) {
    answer = 0;
    height = 3;
    width = n;
    matrix = new int[height][width];

    recur(0, 0);

    return answer;
  }

  public void recur(int y, int x) {
    if (y >= height) return;

    if (x >= width) {
      answer++;
      recur(y + 1, 0);
      return;
    }

    // -
    if (x + 2 < width) {
      matrix[y][x] = 1;
      matrix[y][x + 1] = 1;
      matrix[y][x + 2] = 1;

      recur(y, x + 3);

      matrix[y][x] = 0;
      matrix[y][x + 1] = 0;
      matrix[y][x + 2] = 0;
    }

    // |
    if (y + 2 < height) {
      matrix[y][x] = 2;
      matrix[y + 1][x] = 2;
      matrix[y + 2][x] = 2;

      recur(y, x + 3);

      matrix[y][x] = 0;
      matrix[y + 1][x] = 0;
      matrix[y + 2][x] = 0;
    }

    // ㄱ
    if (y + 2 < height) {}

    return;
  }
}
