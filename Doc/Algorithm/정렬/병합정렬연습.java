package 정렬;

import java.util.Arrays;

public class 병합정렬연습 {
	public static void main(String[] args) {
		int[] arr = new int[] { 78, 99, 21, 22, 3, 2, 4, 60 };
		
		System.out.println("정렬 전 : " + Arrays.toString(arr));
		mergeSort1(arr, 0, arr.length - 1);
		System.out.println("정렬 후 : " + Arrays.toString(arr));
	}
	
	private static void mergeSort1(int[] arr, int left, int right) {
		if(left >= right) return;
		int mid = left + (right - left) / 2;
		mergeSort1(arr, left, mid);
		mergeSort1(arr, mid + 1, right);
		merge1(arr, left, mid, right);
	}

	private static void merge1(int[] arr, int left, int mid, int right) {
		int L = left;
		int R = mid + 1;
		int index = left;
		
		int[] sortedArr = new int[arr.length];
		
		while((L <= mid) && (R <= right)) {
			if(arr[L] > arr[R]) 
				sortedArr[index++] = arr[R++];
			else 
				sortedArr[index++] = arr[L++];
		}
		
		if(R > right) {
			for(int i = L; i <= mid; i++) 
				sortedArr[index++] = arr[i];
		}
		else {
			for(int i = R; i <= right; i++) 
				sortedArr[index++] = arr[i];
		}
		
		for(int i = left; i <= right; i++) 
			arr[i] = sortedArr[i];
	}
}
