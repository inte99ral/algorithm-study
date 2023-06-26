package Silver.Rank1;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    Scanner sc = new Scanner(System.in);
    int[][][] squareCoord = new int[2][2][2];

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            squareCoord[j][k][l] = sc.nextInt();
          }
        }
      }
      // 더 큰 사각형 파악
      if (
        (squareCoord[0][1][0] - squareCoord[0][0][0]) *
        (squareCoord[0][1][1] - squareCoord[0][0][1]) <
        (squareCoord[1][1][0] - squareCoord[1][0][0]) *
        (squareCoord[1][1][1] - squareCoord[1][0][1])
      ) {}
    }

    sc.close();
  }
}
