package Silver.Rank1;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    Scanner sc = new Scanner(System.in);
    int[][] squareCoord = new int[4][2];

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 2; k++) {
          squareCoord[j][k] = sc.nextInt();
        }
      }

      // Print
      // {
      //   System.out.println(Arrays.toString(squareData[0]));
      //   System.out.println(Arrays.toString(squareData[1]));
      //   System.out.println();
      // }

      // a b x y

      // a
      int[][] tempCoord = new int[8][2];
      tempCoord[0][0] = squareCoord[0][0];
      tempCoord[0][1] = squareCoord[2][1];

      tempCoord[1][0] = squareCoord[0][0];
      tempCoord[1][1] = squareCoord[3][1];

      tempCoord[2][0] = squareCoord[1][0];
      tempCoord[2][1] = squareCoord[2][1];

      tempCoord[3][0] = squareCoord[1][0];
      tempCoord[3][1] = squareCoord[3][1];

      tempCoord[4][0] = squareCoord[2][0];
      tempCoord[4][1] = squareCoord[0][1];

      tempCoord[5][0] = squareCoord[3][0];
      tempCoord[5][1] = squareCoord[0][1];

      tempCoord[6][0] = squareCoord[2][0];
      tempCoord[6][1] = squareCoord[1][1];

      tempCoord[7][0] = squareCoord[3][0];
      tempCoord[7][1] = squareCoord[1][1];

      for (int[] iArr : tempCoord) System.out.println(Arrays.toString(iArr));

      System.out.println();
      // // a
      // else if (squareData[0][2] + squareData[0][3] < squareData[1][2] + squareData[1][3]) {}
      // // a
      // else if (squareData[0][2] + squareData[0][3] < squareData[1][2] + squareData[1][3]) {}
      // // a
      // System.out.println("d");
    }

    sc.close();
  }
}
