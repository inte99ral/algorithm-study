package Problem.Unsolved.Programmers.Level3.No42627;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;

class Main {
  private static BufferedReader br;
  private static int[][] jobs;

  public static void main(String[] args) throws IOException{
    List<Integer> tempList = new ArrayList<Integer>();
    String line = "";

    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    line = br.readLine();
    line = line.substring(2, line.length() - 2);
    
    for (String numberSet : line.split("\\], \\["))
      for(String number : numberSet.split(", "))
        tempList.add(Integer.parseInt(number));


    br.close();
    return;
  }

  public int solution(int[][] jobs) {
    System.out.println("test code");
    return 0;
  }
}