/** 풀이 1 : 서로소 알고리즘 사용 ========================================
 * 데이터를 집어 넣으면서 8방향 주변에 연결되어 있는 배열을 확인
 * 각 배열 안에는 연결되어있는 다른 배열 중 가장 작은 좌표값을 가지고 있다.
 * 결국, 데이터를 다 집어넣고 난 이후에는 배열 값 == 본인 좌표값 인 배열의 수가 연결되어있는 섬의 수이다.
 */
// import java.io.BufferedReader;
// import java.io.FileInputStream;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.StringTokenizer;

// public class Main {
//   final static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
//   final static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};

//   public static void main(String[] args) throws IOException, NumberFormatException {
//     System.setIn(new FileInputStream("question\\input.txt"));
//     {
//       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//       StringTokenizer st;

//       String input = br.readLine();
//       while(input.charAt(0) != '0') {
//         int answer = 0;
//         int W;
//         int H;
//         int[][] matrix;

//         st = new StringTokenizer(input);
//         W = Integer.parseInt(st.nextToken());
//         H = Integer.parseInt(st.nextToken());
//         matrix = new int[H + 2][W + 2];

//         for(int h = 1; h <= H; h++) {
//           st = new StringTokenizer(br.readLine());
//           for(int w = 1; w <= W; w++) {
//             matrix[h][w] = Integer.parseInt(st.nextToken());

//             if(matrix[h][w] == 0) continue;

//             matrix[h][w] = h * (W + 2) + w; // 본인 좌표값 할당

//             for(int i = 0; i < 8; i++) {
//               int y = h + dy[i];
//               int x = w + dx[i];

//               if(matrix[y][x] == 0) continue;

//               while(matrix[y][x] != y * (W + 2) + x) {
//                 int temp = matrix[y][x];
//                 y = temp / (W + 2);
//                 x = temp % (W + 2);
//               }
              
//               if(matrix[h][w] < matrix[y][x]) matrix[y][x] = matrix[h][w];
//               else matrix[matrix[h][w] / (W + 2)][matrix[h][w] % (W + 2)] = matrix[y][x];
//             }
//           }
//         }

//         for(int h = 1; h <= H; h++) for(int w = 1; w <= W; w++) if(matrix[h][w] == h * (W + 2) + w) answer++;
//         System.out.println(answer);
//         input = br.readLine();
//       }

//       br.close();
//     }

//     return;
//   }
// }

/** 풀이 2 : DFS 알고리즘 사용 ========================================
 * 데이터 다 받고 나서 DFS로 연결된 모든 섬 삭제
 */
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static int w;
	private static int h;
	private static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
	private static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
	private static int[][] matrix;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("question\\input.txt"));
		br = new BufferedReader(new InputStreamReader(System.in));
		
		st = new StringTokenizer(br.readLine());
		
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		int result = 0;
		
		while((w != 0) && (h != 0)) {
			matrix = new int[h][w];
			for(int y = 0; y < h; y++) {
				st = new StringTokenizer(br.readLine());
				for(int x = 0; x < w; x++) {
					matrix[y][x] = st.nextToken().equals("1")? 1 : 0;
				}
			}
			
			for(int y = 0; y < h; y++) {
				for(int x = 0; x < w; x++) {
					if(matrix[y][x] == 1) {
						result++;
						connectionCheck(y, x);
					}
				}
			}
			
			// output
			System.out.println(result);
			
			// init
			st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			result = 0;
		}
		
		return;
	}
	
	public static void connectionCheck(int y, int x) {
		for(int i = 0; i < 8; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if((0 <= Y) && (Y < h) && (0 <= X) && (X < w) && (matrix[Y][X] == 1)) {
				matrix[Y][X] = 2;
				connectionCheck(Y, X);
			}
		}
	}
}
