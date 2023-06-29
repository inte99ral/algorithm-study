package Baekjoon;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  private static BufferedReader br;

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    System.out.println(solution(Integer.parseInt(br.readLine())));

    br.close();
    return;
  }

  public static int solution(int N) {
    int i = 1;
    while ((i * (i - 1) * 3 + 1) < N) i++;

    return i;
  }
}
