import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Solution {

  private static BufferedReader br;
  private static int[][] jobs;

  public static void main(String[] args) throws IOException {
    Solution solutionClass = new Solution();
    List<Integer> tempList = new ArrayList<Integer>();
    String line = "";

    System.setIn(new FileInputStream("input.txt"));
    br = new BufferedReader(new InputStreamReader(System.in));

    line = br.readLine();
    line = line.substring(2, line.length() - 2);

    for (String numberSet : line.split("\\], \\[")) for (String number : numberSet.split(
      ", "
    )) tempList.add(Integer.parseInt(number));

    jobs = new int[tempList.size() / 2][2];

    for (int i = 0; i < tempList.size(); i++) jobs[i / 2][i % 2] = tempList.get(i);

    System.out.println("[ANSWER]: " + solutionClass.solution(jobs));

    br.close();
    return;
  }

  public int solution(int[][] jobs) {
    int answer = 0;

    int[] testArr = { 1, 2, 3 };
    comb(testArr);

    return answer;
  }

  public void comb(int[] jobs) {
    combRecur(jobs, new int[jobs.length], 0, 0);
    return;
  }

  public void combRecur(int[] jobs, int[] selected, int index, int length) {
    if (length == jobs.length) {
      System.out.print("[ ");
      for (int i : selected) System.out.print(i + " ");
      System.out.print("]\n");

      return;
    }

    if (index == jobs.length) return;

    System.out.println("cycle");
    combRecur(jobs, selected, index + 1, length);
    selected[index] = jobs[index];
    combRecur(jobs, selected, index + 1, length + 1);
    return;
  }

  public void cal(int[][] jobs) {}
}
