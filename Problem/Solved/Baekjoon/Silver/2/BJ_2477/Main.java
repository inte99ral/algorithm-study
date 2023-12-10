/*
 * 해설 ㄱ 자 모양을 추측하기 위하여 가장 긴 변 두개를 찾고
 * 그 후에 2번 뒤에 나올 부분이 ㄱ자의 꺾이는 부분임을 파악
 */

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
    int maxHIndex = -1;
    int maxVIndex = -1;

    {
      st = new StringTokenizer(br.readLine());
      // Horizontal
      if (Integer.parseInt(st.nextToken()) < 3) {
        lenArr[0] = Integer.parseInt(st.nextToken());
        maxHIndex = 0;
        maxVIndex = 1;
      }
      // Vertical
      else {
        lenArr[0] = Integer.parseInt(st.nextToken());
        maxHIndex = 1;
        maxVIndex = 0;
      }
    }

    for (int i = 1; i < 6; i++) {
      st = new StringTokenizer(br.readLine());

      // Horizontal
      if (Integer.parseInt(st.nextToken()) < 3) {
        lenArr[i] = Integer.parseInt(st.nextToken());
        if (lenArr[i] > lenArr[maxHIndex]) maxHIndex = i;
      }
      // Vertical
      else {
        lenArr[i] = Integer.parseInt(st.nextToken());
        if (lenArr[i] > lenArr[maxVIndex]) maxVIndex = i;
      }
    }

    // maxVIndex -> maxHIndex 순서일 때
    if ((maxVIndex + 1) % 6 == maxHIndex) {
      System.out.println(
        (
          lenArr[maxHIndex] *
          lenArr[maxVIndex] -
          lenArr[(maxHIndex + 2) % 6] *
          lenArr[(maxVIndex + 4) % 6]
        ) *
        K
      );
    }
    // maxHIndex -> maxVIndex 순서일 때
    else {
      System.out.println(
        (
          lenArr[maxHIndex] *
          lenArr[maxVIndex] -
          lenArr[(maxHIndex + 4) % 6] *
          lenArr[(maxVIndex + 2) % 6]
        ) *
        K
      );
    }

    br.close();
    return;
  }
}
