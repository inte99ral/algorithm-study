package Problem.Unsolved.Programmers.Level3.No42627;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;

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

    solutionClass.solution(jobs);
    br.close();
    return;
  }

  public int solution(int[][] jobs) {
    int answer = 0;
    int time = 0;
    PriorityQueue<int[]> pq = new PriorityQueue<int[]>((x, y)->((x[1] - x[0]) - (y[1] - y[0])));
    
    for(int[] job : jobs) 
      pq.offer(job);
    
    while(pq.size() != 0) {
      int[] tempArr = pq.poll();
      answer += time + tempArr[0] - tempArr[1];
      time = tempArr[1];
    }

    System.out.println("[LENGTH]: " + jobs.length);
    System.out.println("[ANSWER]: " + answer / jobs.length);
    
    return answer / jobs.length;
  }
}