package BJ.Bronze.B1;
// https://www.acmicpc.net/problem/2563

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_2563_색종이 {
    private static BufferedReader br;
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException{
        System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        int[][] canvas = new int[100][100];
        int result = 0;

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            // 색종이 크기 10
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(canvas[y+i][x+j]++ == 0) result++;
                }
            }
        }

        System.out.println(result);
    }
}