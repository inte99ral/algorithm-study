package Baekjoon;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  private static BufferedReader br;

  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("input.txt")); // -- 로컬 input.txt 입력 코드
    
    br = new BufferedReader(new InputStreamReader(System.in));

    for (String line = br.readLine(); line != null; line = br.readLine()) System.out.println(line);
    // arr = Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
    br.close();
    return;
  }
}
