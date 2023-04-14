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

    System.out.println("[ANSWER]: " + solutionClass.solution(jobs));

    br.close();
    return;
  }

  public int solution(int[][] jobs) {
    int answer = 0;
    int currTime = 0;
    PriorityQueue<int[]> jobQueue = new PriorityQueue<int[]>((x, y) -> (x[0] - y[0]));
    PriorityQueue<int[]> waitingQueue = new PriorityQueue<int[]>((x, y) -> (x[1] - y[1]));
    
    for(int[] job : jobs) 
      jobQueue.offer(job);

    System.out.println("루프 체크1");
    
    while(jobQueue.size() != 0 || waitingQueue.size() != 0) {
      // 현 시간에 밀려있는 작업들을 대기열로 이동
      while(jobQueue.size() != 0 && jobQueue.peek()[0] < currTime){
        waitingQueue.offer(jobQueue.poll());
      }

      // 대기열이 없다면 가장 먼저 요청이 들어온 것을 처리
      if(waitingQueue.size() == 0) {
        int[] currJob = jobQueue.poll();
        currTime = currJob[0] + currJob[1];

        // 작업은 곧바로 시작되어 작업 시간 만큼만 기다렸다
        answer += currJob[1];

        System.out.println("대기 X: " + currJob[1]);
        System.out.println("curr: " + currTime);
        System.out.println("[0]: " + currJob[0]);
        System.out.println("[1]: " + currJob[1]);
      }
      // 대기열이 있다면 그 중에서 제일 빨리 끝낼 수 있는 것을 우선시
      else {
        int[] currJob = waitingQueue.poll();
        currTime += currJob[1];

        // 작업은 최신 시간에서 요청된 시간을 뺀 만큼 기다렸다
        answer += currTime - currJob[0];

        System.out.println("대기 O: " + (currTime - currJob[0] + currJob[1]));
        System.out.println("curr: " + currTime);
        System.out.println("[0]: " + currJob[0]);
        System.out.println("[1]: " + currJob[1]);
      }
    }

    // 평균
    answer /= jobs.length;

    return answer;
  }
}