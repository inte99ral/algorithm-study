import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private static BufferedReader br;
	private static char[][] image;
	private static int MATRIX_SIZE;
	private static Queue<Character> answer;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("question/input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		
		answer = new LinkedList<>();
		MATRIX_SIZE = Integer.parseInt(br.readLine());
		image = new char[MATRIX_SIZE][MATRIX_SIZE];
		for(int y = 0; y < MATRIX_SIZE; y++) image[y] = br.readLine().toCharArray();
		
		
		answer.offer('(');
		
		// 여기서 재귀함수를 돌면서 n/2 씩 확인 체크한다.
		
		answer.offer(')');
		
		System.out.println(answer.toString().replaceAll("[\\[\\,\\ \\]]", ""));
	}
	
	
	
	
	
	private static boolean tileCheck(int Y, int X, int size) {
		for(int y = Y; y < size; y++) 
			for(int x = X; x < size; x++) 
				if(image[Y][X] != image[y][x]) 
					return false;
		
		return true;
	}
	
}
