/**
 * java Main.java
 */

package Baekjoon;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException {
    System.setIn(new FileInputStream("question/input.txt")); // -- 로컬 input.txt 입력 코드
    BufferedReader br;

    br = new BufferedReader(new InputStreamReader(System.in));

    // -- String line
    // for (String line = br.readLine(); line != null; line = br.readLine()) System.out.println(line);
    // -- Int Array
    for(int i : Arrays.stream(br.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray()) System.out.println(i);
    
    br.close();
    return;
  }
}
