package BJ.Bronze.B2;
// https://www.acmicpc.net/problem/1592

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class BJ_1592_영식이친구 {
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int[] friend = new int[N];
        int index = 0;
        int max = 0;
        int count = -1;
        while(max < M){
            count++;
            friend[index]++;
            if(max < friend[index]) max = friend[index];
            index = (index + L) % N;
        }
        System.out.println(count);
    }
}