package 정렬;

import java.util.Arrays;

public class 버블정렬 {
	private static int[] arr = {2, 9, 6, 1, 7, 5, 3, 8, 4};
	
	public static void main(String[] args) {
		bubbleSort(arr, 9);
		System.out.println(Arrays.toString(arr));
	}
	
	private static void bubbleSort(int[] arr, int size) {
		for(int i = 1; i < size; i++) {
			
			boolean swapped = false;
			
			for(int j = 0; j < size - i; j++) {
				// 앞, 뒤를 확인하고 큰 값을 앞으로 밀어낸다.
				if(arr[j] > arr[j + 1]) {
					swap(arr, j, j + 1);
					swapped = true;
				}
			}
			
			// 이미 정렬이 되어있다 -> 최소 N번 탐색 종료
			if(!swapped) break;
		}
		
		return;
	}
	
	private static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		return;
	}
}
