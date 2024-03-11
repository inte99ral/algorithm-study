package 그래프.완전탐색;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 배열 순회
public class ArrayTraversal {
	private static final int MATRIX_SIZE = 4;
	private static final int[] dy = {0, 1, 0, -1};
	private static final int[] dx = {1, 0, -1, 0};
	
	// 일반적인 방향
	private static final String input1 = 
			"01 02 03 04\r\n" + 
			"05 06 07 08\r\n" + 
			"09 10 11 12\r\n" + 
			"13 14 15 16";
	
	// 지그재그
	private static final String input2 = 
			"01 02 03 04\r\n" + 
			"08 07 06 05\r\n" + 
			"09 10 11 12\r\n" + 
			"16 15 14 13";
	
	// 대각선
	private static final String input3 = 
			"01 02 04 07\r\n" + 
			"03 05 08 11\r\n" + 
			"06 09 12 14\r\n" + 
			"10 13 15 16";
	
	// 회전
	private static final String input4 = 
			"01 02 03 04\r\n" + 
			"12 13 14 05\r\n" + 
			"11 16 15 06\r\n" + 
			"10 09 08 07";
	
	
	private static BufferedReader br;
	private static StringTokenizer st;
	private static int[][] matrix;
	
	public static void main(String[] args) throws Exception {
		arrayTraversal1();
		arrayTraversal4();
	}
	
	private static void init(int caseNum) throws IOException {
		switch (caseNum) {
		case 1:
			br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(input1.getBytes())));
			break;
		case 2:
			br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(input2.getBytes())));
			break;
		case 3:
			br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(input3.getBytes())));
			break;
		case 4:
			br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(input4.getBytes())));
			break;
		}
		
		matrix = new int[MATRIX_SIZE][MATRIX_SIZE];
		
		for(int y = 0; y < MATRIX_SIZE; y++) {
			st = new StringTokenizer(br.readLine());
			for(int x = 0; x < MATRIX_SIZE; x++) {
				matrix[y][x] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	private static void arrayTraversal1() throws Exception {
		init(1);
		
		for(int y = 0; y < MATRIX_SIZE; y++) {
			for(int x = 0; x < MATRIX_SIZE; x++) {
				System.out.print(matrix[y][x]);
				System.out.print(" ");
			}
		}
		
		System.out.println();
	}
	
	private static void arrayTraversal4() throws Exception {
		init(4);
		
		int y = 0;
		int x = 0;
		for(int i = MATRIX_SIZE - 1; i > 0; i -= 2) {
			for(int j = 0; j < 4; j++) {
				for(int k = 0; k < i; k++) {
					System.out.print(matrix[y][x]);
					System.out.print(" ");				
					
					y += dy[j];
					x += dx[j];
				}
			}
			y++;
			x++;
		}
		
		if((MATRIX_SIZE & 1) != 0) System.out.print(matrix[y][x]);
		System.out.println();
	}
}
