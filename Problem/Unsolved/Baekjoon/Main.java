package Baekjoon;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  private static BufferedReader br;
  private static StringTokenizer st;

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    int K = Integer.parseInt(br.readLine());

    int[] lenArr = new int[6];
    int index = 0;
    int maxHIndex = 0;
    int maxVIndex = 0;

    for (String line = br.readLine(); line != null; line = br.readLine()) {
      st = new StringTokenizer(line);

      // Horizontal
      if (Integer.parseInt(st.nextToken()) < 3) {
        lenArr[index] = Integer.parseInt(st.nextToken());
        if (lenArr[index] > lenArr[maxHIndex]) maxHIndex = index;
      }
      // Vertical
      else {
        lenArr[index] = Integer.parseInt(st.nextToken());
        if (lenArr[index] > lenArr[maxVIndex]) maxVIndex = index;
      }

      index++;
    }

    // maxVIndex -> maxHIndex 순서일 때
    if ((maxVIndex + 1) % 6 == maxHIndex) {
      System.out.println(
        (lenArr[maxHIndex] * lenArr[maxVIndex] - lenArr[maxHIndex + 2] * lenArr[maxVIndex + 4]) * K
      );
    }
    // maxHIndex -> maxVIndex 순서일 때
    else {
      System.out.println(
        (lenArr[maxHIndex] * lenArr[maxVIndex] - lenArr[maxHIndex + 4] * lenArr[maxVIndex + 2]) * K
      );
    }

    br.close();
    return;
  }
}
