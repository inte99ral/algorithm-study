package Problem.Unsolved.Programmers.Level3.No42627;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;

class Solution {
  private static BufferedReader br;
  private static int[][] jobs;

  public static void main(String[] args) throws IOException{
    Solution solutionClass = new Solution();
    List<Integer> tempList = new ArrayList<Integer>();
    String line = "";

    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    line = br.readLine();
    line = line.substring(2, line.length() - 2);
    
    for (String numberSet : line.split("\\], \\["))
      for(String number : numberSet.split(", "))
        tempList.add(Integer.parseInt(number));

    jobs = new int[tempList.size() / 2][2];

    for(int i = 0; i < tempList.size(); i++)
      jobs[i / 2][i % 2] = tempList.get(i);

    System.out.println("[ANSWER]: " + solutionClass.solution(jobs));

    br.close();
    return;
  }

  public int solution(int[][] jobs) {
    int answer = 0;

    

    return answer;
  }

  public void comb(int[][] jobs) {
    combRecur(jobs, new int[jobs.length][jobs[0].length], 0, 0);
    return;
  }

  public void combRecur(int[][] jobs, int[][] selected, int index, int length) {
    if(index == jobs.length) {
      for(int[] iArr : selected) {
        System.out.print(iArr[0] + "-");
      }
    }
    return;
  }

  public void cal(int[][] jobs) {

  }
}