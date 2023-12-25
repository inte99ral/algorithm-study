package BJ.Bronze.B2;
// https://www.acmicpc.net/problem/2798

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_2798_블랙잭 {
    private static BufferedReader br;
    private static StringTokenizer st;
    private static int N;
    private static int M;
    private static int max;
    private static int[] card;

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken()); // black jack

        card = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int n = 0; n < N; n++) card[n] = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N - 2; i++){
            for(int j = i + 1; j < N - 1; j++){
                for(int k = j + 1; k < N; k++){
                    int sum = card[i] + card[j] + card[k];
                    if((max < sum) && (sum <= M)) max = sum;
                }
            }
        }

        System.out.println(max);
    } 
}
