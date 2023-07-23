package BJ.Silver.S4;
// https://www.acmicpc.net/problem/2567

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_2567_색종이2 {
    private static final int MATRIX_SIZE = 100;
    private static final int PAPER_SIZE = 10;
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] matrix = new int[MATRIX_SIZE + 2][MATRIX_SIZE + 2];

        int N = Integer.parseInt(br.readLine());
        for(int n = 0; n < N; n++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken()) + 1;
            int Y = Integer.parseInt(st.nextToken()) + 1;
            for(int y = Y; y < Y + PAPER_SIZE; y++) for(int x = X; x < X + PAPER_SIZE; x++) matrix[y][x]++;
        }

        int result = 0;
        for(int y = 0; y < MATRIX_SIZE + 2; y++){
            for(int x = 0; x < MATRIX_SIZE + 2; x++){
                if(matrix[y][x] != 0) continue;
                if((y != 0)&&(matrix[y - 1][x] != 0)) result++;
                if((y != MATRIX_SIZE + 1)&&(matrix[y + 1][x] != 0)) result++;
                if((x != 0)&&(matrix[y][x - 1] != 0)) result++;
                if((x != MATRIX_SIZE + 1)&&(matrix[y][x + 1] != 0)) result++;
            }
        }

        System.out.println(result);
    }
}
