/**
 * solution 메소드만 코딩하면 되기 때문에 main 만 지울 것
 */
package Programmers;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
  private static BufferedReader br;

  public static void main(String[] args) throws IOException{
    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    for(String line = br.readLine(); line != null; line = br.readLine())
      System.out.println(line);

    br.close();
    return;
  }

  public int solution(int[][] jobs) {
    System.out.println("test code");
    return 0;
  }
}