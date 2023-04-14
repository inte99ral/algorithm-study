import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    Scanner sc = new Scanner(System.in);
    int[][] squareData = new int[2][4];

    for (int i = 0; i < 4; i++) {
      // System.out.println(sc.nextLine());
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 4; k++) {
          squareData[j][k] = sc.nextInt();
        }
      }

      // Print
      {
        System.out.println(Arrays.toString(squareData[0]));
        System.out.println(Arrays.toString(squareData[1]));
        System.out.println();
      }

      if (squareData[0][2] + squareData[0][3] < squareData[1][2] + squareData[1][3]) {}
    }

    sc.close();
  }
}
