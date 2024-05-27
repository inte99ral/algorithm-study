import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BR {
	private static String input1 =
			"7 8\r\n" + 
			"0 0 0 0 0 0 1 1\r\n" + 
			"1 1 0 0 0 0 1 1\r\n" + 
			"1 1 0 0 0 0 0 0\r\n" + 
			"1 1 0 0 0 1 1 0\r\n" + 
			"0 0 0 0 0 1 1 0\r\n" + 
			"0 0 0 0 0 0 0 0\r\n" + 
			"1 1 1 1 1 1 1 1";
	
	private static String input2 = 
			"7 7\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"0 0 0 0 0 0 0\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1\r\n" + 
			"1 1 1 0 1 1 1";
	
	public static void main(String[] args) throws Exception {
		BufferedReader br;
    StringTokenizer st;
    int Y;
    int X;

    // System.setIn(new FileInputStream("input.txt"));
		// br = new BufferedReader(new InputStreamReader(System.in));
    br = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(input2.getBytes())));
    st = new StringTokenizer(br.readLine());
    Y = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());

    int[][] matrix = new int[Y][X];
		
    for (int y = 0; y < Y; y++) {
      st = new StringTokenizer(br.readLine());
      for (int x = 0; x < X; x++) {
        matrix[y][x] = Integer.parseInt(st.nextToken());
        System.out.print(matrix[y][x]);
      }
    }

    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        System.out.printf("%02d",matrix[y][x]);
        System.out.print(", ");
      }
      System.out.print("\b\b \n");
    }
	}
}
